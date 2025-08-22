#pragma once

#include <aidl/android/vendor/coda/BnObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/IObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/IDoorStateReadings.h>
#include <aidl/android/vendor/coda/IRPMReadings.h>
#include <aidl/android/vendor/coda/ISpeedReadings.h>
#include <aidl/android/vendor/coda/IUltrasonicReadings.h>
#include <android/binder_ibinder.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <android/log.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

#define LOG_TAG "ServiceBinding"

namespace aidl::android::vendor::coda {
	class ObservationIVIContract : public aidl::android::vendor::coda::BnObservationServiceIVIContract {
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
			::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::ISpeedReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IRPMReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IUltrasonicReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IDoorStateReadings>& in_cb) override;
  			::ndk::ScopedAStatus changeSystemTheme(bool in_isLightMode) override;
			void startCallbackThread();
			void stopCallbackThread();
	};
}
