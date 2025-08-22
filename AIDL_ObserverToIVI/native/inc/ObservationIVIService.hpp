#pragma once

#include <aidl/android/vendor/coda/observer/BnObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/observer/IObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/observer/IDoorStateReadings.h>
#include <aidl/android/vendor/coda/observer/IRPMReadings.h>
#include <aidl/android/vendor/coda/observer/ISpeedReadings.h>
#include <aidl/android/vendor/coda/observer/IUltrasonicReadings.h>
#include <android/binder_ibinder.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <android/log.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

#define LOG_TAG "ServiceBinding"

namespace aidl::android::vendor::coda::observer {
	class ObservationIVIContract : public aidl::android::vendor::coda::observer::BnObservationServiceIVIContract {
		private:
    		std::shared_ptr<IDoorStateReadings> mDoorStateCb;
    		std::shared_ptr<IRPMReadings> mRPMValCb;
    		std::shared_ptr<ISpeedReadings> mSpeedValCb;
    		std::shared_ptr<IUltrasonicReadings> mUltrasonicReadingCb;
			std::atomic<bool> mRunning{false};
			std::thread mWorkerThread;
		
		public:
			ObservationIVIContract();
			~ObservationIVIContract();
			::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observer::ISpeedReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observer::IRPMReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observer::IUltrasonicReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observer::IDoorStateReadings>& in_cb) override;
  			::ndk::ScopedAStatus changeSystemTheme(bool in_isLightMode) override;
			void startCallbackThread();
			void stopCallbackThread();
	};
}
