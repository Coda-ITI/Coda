#pragma once

#include <aidl/android/vendor/coda/observation/BnObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/observation/IObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/observation/IDoorStateReadings.h>
#include <aidl/android/vendor/coda/observation/IRPMReadings.h>
#include <aidl/android/vendor/coda/observation/ISpeedReadings.h>
#include <aidl/android/vendor/coda/observation/IUltrasonicReadings.h>
#include <aidl/android/vendor/coda/observation/DoorState.h>
#include <android/binder_ibinder.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <android/log.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>
#include <unordered_map>

#define LOG_TAG "ServiceBinding"

namespace aidl::android::vendor::coda::observation {
	class ObservationIVIContract : public aidl::android::vendor::coda::observation::BnObservationServiceIVIContract {
		private:
    		std::shared_ptr<IDoorStateReadings> mDoorStateCb;
    		std::shared_ptr<IRPMReadings> mRPMValCb;
    		std::shared_ptr<ISpeedReadings> mSpeedValCb;
			std::vector<std::shared_ptr<IUltrasonicReadings>> mUltrasonicReadingCbs{4};
			std::atomic<bool> mRunning{false};
			std::thread mWorkerThread;
		
		public:
			ObservationIVIContract();
			~ObservationIVIContract();
			::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::ISpeedReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IRPMReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb, int32_t in_sensorIndex) override;
  			::ndk::ScopedAStatus registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) override;
  			::ndk::ScopedAStatus changeSystemTheme(bool in_isLightMode) override;
			void startCallbackThread();
			void stopCallbackThread();
	};
}
