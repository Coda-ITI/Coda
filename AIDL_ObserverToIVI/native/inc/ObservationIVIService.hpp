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
#include <v1/coda/vehicle/PerceptionProxy.hpp>
#include <IVIStubImpl.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <memory>
#include <vector>
#include <array>
#include <mutex>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LOG_TAG "ServiceBinding"

namespace aidl::android::vendor::coda::observation {
	class ObservationIVIContract : public aidl::android::vendor::coda::observation::BnObservationServiceIVIContract
	{
		private:
			static constexpr int NUM_ULTRASONIC_SENSORS = 4;

			static constexpr uint32_t FRONT_LEFT_DOOR = 0;
			static constexpr uint32_t FRONT_RIGHT_DOOR = 1;
			static constexpr uint32_t REAR_LEFT_DOOR = 2;
			static constexpr uint32_t REAR_RIGHT_DOOR = 3;
			static constexpr uint32_t NUM_OF_DOORS = 4;

			static constexpr uint32_t ULTRASONIC_1 = 0;
			static constexpr uint32_t ULTRASONIC_2 = 1;
			static constexpr uint32_t ULTRASONIC_3 = 2;
			static constexpr uint32_t ULTRASONIC_4 = 3;
			static constexpr uint32_t NUM_OF_ULTRASONICS = 4;

			std::vector<std::shared_ptr<IDoorStateReadings>> mDoorStateCbs{NUM_OF_DOORS};
    		std::shared_ptr<IRPMReadings> mRPMValCb;
    		std::shared_ptr<ISpeedReadings> mSpeedValCb;
			std::vector<std::shared_ptr<IUltrasonicReadings>> mUltrasonicReadingCbs{NUM_OF_ULTRASONICS};
			
			std::shared_ptr<v1::coda::vehicle::PerceptionProxyDefault> perceptionProxy_;
			std::shared_ptr<v1::coda::vehicle::IVIStubImpl> iviStub_;

			CommonAPI::Event<uint16_t>::Subscription speedSubscription_;
			CommonAPI::Event<uint16_t>::Subscription rpmSubscription_;
			CommonAPI::Event<std::vector<v1::coda::vehicle::Perception::S_DoorState>>::Subscription multiDoorSubscription_;
			std::array<CommonAPI::Event<float>::Subscription,NUM_ULTRASONIC_SENSORS> ultrasonicSubscriptions_;

			std::atomic<bool> isSomeIpInit_{false};

			void handleSpeedChange(const uint16_t& speed);
			void handleRPMChange(const uint16_t& rpm);
			void handleDoorStateChange(const std::vector<v1::coda::vehicle::Perception::S_DoorState>& doorStates);

			void startEvsApp();
			void stopEvsApp();
			
			pid_t evsAppPid_ = -1;
			std::mutex evsAppMutex_;
			bool isEvsAppRunning_ = false;

		public:
			ObservationIVIContract();
			~ObservationIVIContract();
		
			bool initSomeIP();
		
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
	};
}
