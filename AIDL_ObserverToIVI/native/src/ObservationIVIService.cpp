#include "ObservationIVIService.hpp"

namespace aidl::android::vendor::coda::observer {
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
	::ndk::ScopedAStatus ObservationIVIContract::registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observer::ISpeedReadings>& in_cb) 
	{
		this->mSpeedValCb = in_cb;
		if (in_cb != nullptr)
		{
			__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "speed callback registered successfully");
		}
	    return ::ndk::ScopedAStatus::ok();
	}

	::ndk::ScopedAStatus ObservationIVIContract::registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observer::IRPMReadings>& in_cb) 
	{
		this->mRPMValCb = in_cb;
		if (in_cb != nullptr)
		{
			__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "rpm callback registered successfully");
		}
	    return ::ndk::ScopedAStatus::ok();
	}

	::ndk::ScopedAStatus ObservationIVIContract::registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observer::IUltrasonicReadings>& in_cb) 
	{
		this->mUltrasonicReadingCb = in_cb;
		if (in_cb != nullptr)
		{
			__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "ultrasonic callback registered successfully");
		}
		return ::ndk::ScopedAStatus::ok();
	}

	::ndk::ScopedAStatus ObservationIVIContract::registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observer::IDoorStateReadings>& in_cb) 
	{
		/*if (in_cb != nullptr)
		{
			this->mVehicleCb = in_cb;	
		}*/
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

	void ObservationIVIContract::startCallbackThread() 
	{
	    mRunning = true;
	    mWorkerThread = std::thread([this]() {
	        while (mRunning) 
			{
	            std::this_thread::sleep_for(std::chrono::seconds(3));

	            if (mDoorStateCb) mDoorStateCb->onDoorStateChanged(1, true);
	            if (mRPMValCb) mRPMValCb->onRpmChanged(1500);
	            if (mSpeedValCb) mSpeedValCb->onSpeedChanged(80);
	            if (mUltrasonicReadingCb) mUltrasonicReadingCb->onUltrasonicChanged(2, 6.9);
	        }
	    });
	}

	void ObservationIVIContract::stopCallbackThread() 
	{
	    mRunning = false;
	    if (mWorkerThread.joinable()) 
		{
	        mWorkerThread.join();
	    }
	}
}
