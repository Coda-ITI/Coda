#pragma once

#include <aidl/android/vendor/coda/observation/BnObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/observation/IObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/observation/IDoorStateReadings.h>
#include <aidl/android/vendor/coda/observation/IRPMReadings.h>
#include <aidl/android/vendor/coda/observation/ISpeedReadings.h>
#include <aidl/android/vendor/coda/observation/IUltrasonicReadings.h>
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

constexpr uint32_t FRONT_LEFT_DOOR = 0;
constexpr uint32_t FRONT_RIGHT_DOOR = 1;
constexpr uint32_t REAR_LEFT_DOOR = 2;
constexpr uint32_t REAR_RIGHT_DOOR = 3;
constexpr uint32_t NUM_OF_DOORS = 4;

constexpr uint32_t ULTRASONIC_0 = 0;
constexpr uint32_t ULTRASONIC_1 = 1;
constexpr uint32_t ULTRASONIC_2 = 2;
constexpr uint32_t ULTRASONIC_3 = 3;
constexpr uint32_t NUM_OF_ULTRASONICS = 4;

namespace aidl::android::vendor::coda::observation {
	class ObservationIVIContract : public aidl::android::vendor::coda::observation::BnObservationServiceIVIContract {
		private:
			std::vector<std::shared_ptr<IDoorStateReadings>> mDoorStateCbs{NUM_OF_DOORS};
    		std::shared_ptr<IRPMReadings> mRPMValCb;
    		std::shared_ptr<ISpeedReadings> mSpeedValCb;
			std::vector<std::shared_ptr<IUltrasonicReadings>> mUltrasonicReadingCbs{NUM_OF_ULTRASONICS};
			std::atomic<bool> mRunning{false};
			std::thread mWorkerThread;
		
		public:
			ObservationIVIContract();
			~ObservationIVIContract();
			
			::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::ISpeedReadings>& in_cb) override;
  			
			::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IRPMReadings>& in_cb) override;
  			
			::ndk::ScopedAStatus registerUltrasonic0ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerUltrasonic1ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerUltrasonic2ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerUltrasonic3ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) override;
  			
			::ndk::ScopedAStatus registerDoorStateFLReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerDoorStateFRReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerDoorStateRLReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) override;
  			::ndk::ScopedAStatus registerDoorStateRRReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) override;
  			
			::ndk::ScopedAStatus changeSystemThemeToLight() override;
  			::ndk::ScopedAStatus changeSystemThemeToDark() override;

			void startCallbackThread() ;
  			void stopCallbackThread();
	};
}
