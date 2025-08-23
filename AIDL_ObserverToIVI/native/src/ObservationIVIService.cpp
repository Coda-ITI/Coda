#include "ObservationIVIService.hpp"

namespace aidl::android::vendor::coda {


bool ObservationIVIContract::initSomeIP()
{
	// define a bool flag & counter to indicate that app has been initialized successfully
	bool _init = true;
	std::chrono::milliseconds timeoutCycle(100);
	int8_t timeoutCounter = 5;

	// defining capicxx runtime instance
	auto runtime = CommonAPI::Runtime::get();
		
	// define IVI service instance
	std::string domain = "local";
	std::string iviInstance = "coda.vehicle.IVI";
	std::string connection = "IVIApp";

	// initialize perception Proxy (service consumer)
	CommonAPI::Runtime::setProperty("LibraryBase", "Perception");
	std::string perceptionInstance = "coda.vehicle.Perception";
	perceptionProxy_ = runtime->buildProxy<v1::coda::vehicle::PerceptionProxy>(domain, perceptionInstance, connection);
	
	// wait until IVI service is registered successfully

	iviStub_ = std::make_shared<v1::coda::vehicle::IVIStubImpl>();

	while (!runtime->registerService(domain, iviInstance, iviStub_, connection) && (timeoutCounter > 0))
	{
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Failed to register someIp service retrying...");
		std::this_thread::sleep_for(timeoutCycle);
		timeoutCounter--;
	}

	// indicate that service registration has timed out
	if (timeoutCounter <= 0) 
	{
		_init = false;
		perror("SomeIP service registration failed");
	}

	// wait until Perception proxy is available
	if (_init)
	{
		while (!perceptionProxy_->isAvailable())
		{
        	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Perception Proxy not available retrying...");
			std::this_thread::sleep_for(timeoutCycle);
		}
	}
	
	// indicates that perception proxy has timed out
	if (!perceptionProxy_->isAvailable()) 
	{
		_init = false;
		perror("Perception service not available!");
		goto out;
	}
	
	// subscribe to Perception events
	speedSubscription_ = perceptionProxy_->getNotifySpeedEvent().subscribe(
		[this](const uint16_t& speed) {
			this->handleSpeedChange(speed);
		}
	);
	
	rpmSubscription_ = perceptionProxy_->getNotifyRPMEvent().subscribe(
		[this](const uint16_t& rpm) {
			this->handleRPMChange(rpm);
		}
	);
	
	multiDoorSubscription_ = perceptionProxy_->getMultiDoorNotifyEvent().subscribe(
		[this](const std::vector<v1::coda::vehicle::Perception::S_DoorState>& doorStates) {
			this->handleDoorStateChange(doorStates);
		}
	);

	ultrasonicSubscriptions_[0] = perceptionProxy_->getNotifyUltrasonic_1Event().subscribe(
		[this](const float& ultrasonic_1) {
			if (mUltrasonicReadingCbs[0] != nullptr) 
			{
				mUltrasonicReadingCbs[0]->onUltrasonicChanged(ultrasonic_1, 0);
			}
		}
	);

	ultrasonicSubscriptions_[1] = perceptionProxy_->getNotifyUltrasonic_2Event().subscribe(
		[this](const float& ultrasonic_2) {
			if (mUltrasonicReadingCbs[1] != nullptr) 
			{
				mUltrasonicReadingCbs[1]->onUltrasonicChanged(ultrasonic_2, 1);
			}
		}
	);

	ultrasonicSubscriptions_[2] = perceptionProxy_->getNotifyUltrasonic_3Event().subscribe(
		[this](const float& ultrasonic_3) {
			if (mUltrasonicReadingCbs[2] != nullptr) 
			{
				mUltrasonicReadingCbs[2]->onUltrasonicChanged(ultrasonic_3, 2);
			}
		}
	);

	ultrasonicSubscriptions_[3] = perceptionProxy_->getNotifyUltrasonic_4Event().subscribe(
		[this](const float& ultrasonic_4) {
			if (mUltrasonicReadingCbs[3] != nullptr) 
			{
				mUltrasonicReadingCbs[3]->onUltrasonicChanged(ultrasonic_4, 3);
			}
		}
	);
	

	
	std::cout << "Observer App has been initialized successfully!" << std::endl;

	isSomeIpInit_ = _init;
out:
	return _init;
}


ObservationIVIContract::ObservationIVIContract()
{
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Service Object Constructed");
}

ObservationIVIContract::~ObservationIVIContract()
{
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Service Object Destroyed");
	if (isSomeIpInit_ && perceptionProxy_)
	{
		perceptionProxy_->getNotifySpeedEvent().unsubscribe(speedSubscription_);
		perceptionProxy_->getNotifyRPMEvent().unsubscribe(rpmSubscription_);
		perceptionProxy_->getMultiDoorNotifyEvent().unsubscribe(multiDoorSubscription_);
		for (int i = 0; i < NUM_ULTRASONIC_SENSORS; ++i) {
			switch(i) {
				case 0: perceptionProxy_->getNotifyUltrasonic_1Event().unsubscribe(ultrasonicSubscriptions_[i]); break;
				case 1: perceptionProxy_->getNotifyUltrasonic_2Event().unsubscribe(ultrasonicSubscriptions_[i]); break;
				case 2: perceptionProxy_->getNotifyUltrasonic_3Event().unsubscribe(ultrasonicSubscriptions_[i]); break;
				case 3: perceptionProxy_->getNotifyUltrasonic_4Event().unsubscribe(ultrasonicSubscriptions_[i]); break;
			}
		}
	}
}

::ndk::ScopedAStatus ObservationIVIContract::registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::ISpeedReadings>& in_cb) 
{
	this->mSpeedValCb = in_cb;
	if (in_cb != nullptr)
	{
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "speed callback registered successfully");
	}
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IRPMReadings>& in_cb) 
{
	this->mRPMValCb = in_cb;
	if (in_cb != nullptr)
	{
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "rpm callback registered successfully");
	}
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IUltrasonicReadings>& in_cb, int32_t in_sensorIndex) 
{
	if (in_sensorIndex < 0 || in_sensorIndex >= NUM_ULTRASONIC_SENSORS) {
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Invalid sensor index: %d", in_sensorIndex);
		return ::ndk::ScopedAStatus::ok();
	}
	else 
	{
		this->mUltrasonicReadingCbs[in_sensorIndex] = in_cb;
	}
	if (in_cb != nullptr)
	{
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "ultrasonic callback registered successfully");
	}
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IDoorStateReadings>& in_cb) 
{
	this->mDoorStateCb = in_cb;
	if (in_cb != nullptr)
	{
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "door callback registered successfully");
	}
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::changeSystemTheme(bool in_isLightMode) 
{
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "received a flag of value %d to change the system them");
	// notify->changeTheme() /** using IVI stub */

	if(isSomeIpInit_)
	{	
		v1::coda::vehicle::IVI::Theme in_theme = in_isLightMode ? v1::coda::vehicle::IVI::Theme::LIGHT : v1::coda::vehicle::IVI::Theme::DARK;
		iviStub_->notifyThemeChange(in_theme);
	}

	return ::ndk::ScopedAStatus::ok();
}

void ObservationIVIContract::handleSpeedChange(const uint16_t& speed)
{
	if (mSpeedValCb != nullptr) 
	{
		mSpeedValCb->onSpeedChanged(speed);
	}
}

void ObservationIVIContract::handleRPMChange(const uint16_t& rpm)
{
	if (mRPMValCb != nullptr) 
	{
		mRPMValCb->onRpmChanged(rpm);
	}
}
 
void ObservationIVIContract::handleDoorStateChange(const std::vector<v1::coda::vehicle::Perception::S_DoorState>& doorStates)
{
	if (mDoorStateCb != nullptr) 
	{
		std::vector<DoorState> aidlDoorStates;
		for (const auto& state : doorStates) 
		{
			DoorState aidlState;
			aidlState.position = static_cast<int32_t>(state.getDoorPos());

			if (state.getDoorState() == v1::coda::vehicle::Perception::DoorState::OPEN)
			{
				aidlState.isOpen = true;
			}
			else
			{
				aidlState.isOpen = false;
			}

			aidlDoorStates.push_back(aidlState);
		}
		mDoorStateCb->onDoorStateChanged(aidlDoorStates);
	}
}

}

