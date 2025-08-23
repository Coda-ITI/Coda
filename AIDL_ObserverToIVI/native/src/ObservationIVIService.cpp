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

	::ndk::ScopedAStatus ObservationIVIContract::registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb, int32_t in_sensorIndex) 
	{
		
		if (in_cb != nullptr)
		{
			if (in_sensorIndex < 4)
			{
				this->mUltrasonicReadingCbs[in_sensorIndex] = in_cb;
				__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "ultrasonic callback registered successfully");
			}
			else 
			{
				__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "ultrasonic callback invalid index");
			}
		}
		else 
		{
			__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "ultrasonic callback pointer is null");
		}
		return ::ndk::ScopedAStatus::ok();
	}

	::ndk::ScopedAStatus ObservationIVIContract::registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) 
	{
		if (in_cb != nullptr)
		{
			this->mDoorStateCb = in_cb;
			__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "door callback registered successfully");
		}
		else 
		{
			__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "door callback pointer is null");
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
		std::vector<DoorState> doorStates = {
			{.isOpen = true, .position = 0},
			{.isOpen = false, .position = 1},
			{.isOpen = true, .position = 2},
			{.isOpen = false, .position = 3},
		};
		std::unordered_map<int, float> ultrasonicReadings = {
			{0, 1.2},
			{1, 2.4},
			{2, 3.6},
			{3, 4.8},
		};

	    mWorkerThread = std::thread([&, this]() {
	        while (mRunning) 
			{
	            std::this_thread::sleep_for(std::chrono::seconds(3));

	            if (mDoorStateCb != nullptr) mDoorStateCb->onDoorStateChanged(doorStates);
	            if (mRPMValCb != nullptr) mRPMValCb->onRpmChanged(1500);
	            if (mSpeedValCb != nullptr) mSpeedValCb->onSpeedChanged(80);
	            if (!mUltrasonicReadingCbs.empty()) 
				{
					for (uint32_t iter = 0; iter < mUltrasonicReadingCbs.size(); iter++)
					{
						if (mUltrasonicReadingCbs[iter] != nullptr)
							mUltrasonicReadingCbs[iter]->onUltrasonicChanged(iter, ultrasonicReadings[iter]);
					}
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
