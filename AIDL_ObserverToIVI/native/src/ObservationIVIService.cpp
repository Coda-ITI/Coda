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
	
	// make an object of stub impl that is own-able by a shared ptr
	iviStub = std::make_shared<v1::coda::vehicle::IVIStubImpl>();
	
	// define IVI service instance
	std::string domain = "local";
	std::string iviInstance = "coda.vehicle.IVI";
	std::string connection = "IVIApp";

	// initialize perception Proxy (service consumer)
	CommonAPI::Runtime::setProperty("LibraryBase", "Perception");
	std::string perceptionInstance = "coda.vehicle.Perception";
	perceptionProxy = runtime->buildProxy<v1::coda::vehicle::PerceptionProxy>(domain, perceptionInstance, connection);
	
	// wait until IVI service is registered successfully
	while (!runtime->registerService(domain, iviInstance, iviStub_, connection) && (timeoutCounter > 0))
	{
		std::cerr << "Failed to register SomeIP service, retrying..." << std::endl;
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
			perror("Perception proxy not available, retrying...");
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
		[this](const std::vector<Perception::S_DoorState>& doorStates) {
			this->handleDoorStateChange(doorStates);
		}
	);
	

	
	std::cout << "Observer App has been initialized successfully!" << std::endl;

	isSomeIpInit_ = _init;

	return _init;
}


ObservationIVIContract::ObservationIVIContract()
{
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Service Object Constructed");
	startCallbackThread();
}
ObservationIVIContract::~ObservationIVIContract()
{
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Service Object Destroyed");
	stopCallbackThread();
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

	::ndk::ScopedAStatus ObservationIVIContract::registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IUltrasonicReadings>& in_cb) 
	{
		this->mUltrasonicReadingCb = in_cb;
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
	    return ::ndk::ScopedAStatus::ok();
	}
}
