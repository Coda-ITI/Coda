#include "ObservationIVIService.hpp"

namespace aidl::android::vendor::coda::observation {


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
	
	iviStub_ = std::make_shared<v1::coda::vehicle::IVIStubImpl>();

	// wait until IVI service is registered successfully
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
			if (mSpeedValCb != nullptr) 
			{
				mSpeedValCb->onSpeedChanged(speed);
			}
		}
	);
	
	rpmSubscription_ = perceptionProxy_->getNotifyRPMEvent().subscribe(
		[this](const uint16_t& rpm) {
			if (mRPMValCb != nullptr) 
			{
				mRPMValCb->onRpmChanged(rpm);
			}
		}
	);
	
	multiDoorSubscription_ = perceptionProxy_->getMultiDoorNotifyEvent().subscribe(
		[this](const std::vector<v1::coda::vehicle::Perception::S_DoorState>& doorStates) {			
			for (uint32_t iter = FRONT_LEFT_DOOR; iter < NUM_OF_DOORS; iter++)
			{
				if (mDoorStateCbs[iter] != nullptr)
					mDoorStateCbs[iter]->onDoorStateChanged(iter, doorStates[iter].getDoorState());
			}
		}
	);

	ultrasonicSubscriptions_[0] = perceptionProxy_->getNotifyUltrasonic_1Event().subscribe(
		[this](const float& ultrasonic_1) {
			if (mUltrasonicReadingCbs[ULTRASONIC_1] != nullptr) 
			{
				mUltrasonicReadingCbs[ULTRASONIC_1]->onUltrasonicChanged(ULTRASONIC_1, ultrasonic_1);
			}
		}
	);

	ultrasonicSubscriptions_[1] = perceptionProxy_->getNotifyUltrasonic_2Event().subscribe(
		[this](const float& ultrasonic_2) {
			if (mUltrasonicReadingCbs[ULTRASONIC_2] != nullptr) 
			{
				mUltrasonicReadingCbs[ULTRASONIC_2]->onUltrasonicChanged(ULTRASONIC_2, ultrasonic_2);
			}
		}
	);

	ultrasonicSubscriptions_[2] = perceptionProxy_->getNotifyUltrasonic_3Event().subscribe(
		[this](const float& ultrasonic_3) {
			if (mUltrasonicReadingCbs[ULTRASONIC_3] != nullptr) 
			{
				mUltrasonicReadingCbs[ULTRASONIC_3]->onUltrasonicChanged(ULTRASONIC_3, ultrasonic_3);
			}
		}
	);

	ultrasonicSubscriptions_[3] = perceptionProxy_->getNotifyUltrasonic_4Event().subscribe(
		[this](const float& ultrasonic_4) {
			if (mUltrasonicReadingCbs[ULTRASONIC_4] != nullptr) 
			{
				mUltrasonicReadingCbs[ULTRASONIC_4]->onUltrasonicChanged(ULTRASONIC_4, ultrasonic_4);
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

::ndk::ScopedAStatus ObservationIVIContract::registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::ISpeedReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mSpeedValCb = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "speed callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "speed callback pointer is null");
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IRPMReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mRPMValCb = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "rpm callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "rpm callback pointer is null");
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerUltrasonic0ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mUltrasonicReadingCbs[ULTRASONIC_1] = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "ultrasonic 0 callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "ultrasonic 0 callback pointer is null");
	}
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerUltrasonic1ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mUltrasonicReadingCbs[ULTRASONIC_2] = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "ultrasonic 1 callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "ultrasonic 1 callback pointer is null");
	}
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerUltrasonic2ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mUltrasonicReadingCbs[ULTRASONIC_3] = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "ultrasonic 2 callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "ultrasonic 2 callback pointer is null");
	}
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerUltrasonic3ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mUltrasonicReadingCbs[ULTRASONIC_4] = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "ultrasonic 3 callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "ultrasonic 3 callback pointer is null");
	}
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerDoorStateFLReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mDoorStateCbs[FRONT_LEFT_DOOR] = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "door callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "door callback pointer is null");
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerDoorStateFRReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mDoorStateCbs[FRONT_RIGHT_DOOR] = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "door callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "door callback pointer is null");
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerDoorStateRLReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mDoorStateCbs[REAR_LEFT_DOOR] = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "door callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "door callback pointer is null");
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerDoorStateRRReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) 
{
	if (in_cb != nullptr)
	{
		this->mDoorStateCbs[REAR_RIGHT_DOOR] = in_cb;
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "door callback registered successfully");
	}
	else 
	{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "door callback pointer is null");
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::changeSystemThemeToLight() 
{
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Change theme to light has been called");

	if(isSomeIpInit_)
	{	
		iviStub_->notifyThemeChange(v1::coda::vehicle::IVI::Theme::LIGHT);
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::changeSystemThemeToDark() 
{
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Change theme to dark has been called");
	
	if(isSomeIpInit_)
	{	
		iviStub_->notifyThemeChange(v1::coda::vehicle::IVI::Theme::DARK);
	}
	return ::ndk::ScopedAStatus::ok();
}
}

