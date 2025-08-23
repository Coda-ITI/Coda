#include "ObservationIVIService.hpp"

namespace aidl::android::vendor::coda::observation {
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
			this->mUltrasonicReadingCbs[ULTRASONIC_0] = in_cb;
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
			this->mUltrasonicReadingCbs[ULTRASONIC_1] = in_cb;
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
			this->mUltrasonicReadingCbs[ULTRASONIC_2] = in_cb;
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
			this->mUltrasonicReadingCbs[ULTRASONIC_3] = in_cb;
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
		// notify->changeTheme() /** using IVI stub */
	    return ::ndk::ScopedAStatus::ok();
	}

  	::ndk::ScopedAStatus ObservationIVIContract::changeSystemThemeToDark() 
	{
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Change theme to dark has been called");
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

	            if (mDoorStateCb != nullptr) mDoorStateCb->onDoorStateChanged(doorStates);
	            if (mRPMValCb != nullptr) mRPMValCb->onRpmChanged(1500);
	            if (mSpeedValCb != nullptr) mSpeedValCb->onSpeedChanged(80);
				for (uint32_t iter = FRONT_LEFT_DOOR; iter < NUM_OF_DOORS; iter++)
				{
					if (mDoorStateCbs[iter] != nullptr)
						mDoorStateCbs[iter]->onDoorStateChanged(iter, true);
				}
				for (uint32_t iter = ULTRASONIC_0; iter < NUM_OF_ULTRASONICS; iter++)
				{
					if (mUltrasonicReadingCbs[iter] != nullptr)
						mUltrasonicReadingCbs[iter]->onUltrasonicChanged(iter, 1.2 * iter);
				}
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
