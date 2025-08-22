#pragma once

#include <aidl/android/vendor/coda/BnObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/DoorState.h>
#include <aidl/android/vendor/coda/IObservationServiceIVIContract.h>
#include <aidl/android/vendor/coda/IDoorStateReadings.h>
#include <aidl/android/vendor/coda/IRPMReadings.h>
#include <aidl/android/vendor/coda/ISpeedReadings.h>
#include <aidl/android/vendor/coda/IUltrasonicReadings.h>
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

#define LOG_TAG "ServiceBinding"

namespace aidl::android::vendor::coda {
class ObservationIVIContract : public aidl::android::vendor::coda::BnObservationServiceIVIContract,public v1::coda::vehicle::IVIStubImpl {
	private:
	std::shared_ptr<IDoorStateReadings> mDoorStateCb;
	std::shared_ptr<IRPMReadings> mRPMValCb;
	std::shared_ptr<ISpeedReadings> mSpeedValCb;
	std::array<std::shared_ptr<IUltrasonicReadings>> mUltrasonicReadingCbs;
	
	std::shared_ptr<v1::coda::vehicle::PerceptionProxyDefault> perceptionProxy;
	std::shared_ptr<v1::coda::vehicle::IVIStubImpl> iviStub;

	CommonAPI::Event<uint16_t>::Subscription speedSubscription_;
    CommonAPI::Event<uint16_t>::Subscription rpmSubscription_;
    CommonAPI::Event<std::vector<v1::vehicle::coda::Perception::S_DoorState>::Subscription multiDoorSubscription_;
	std::vector<CommonAPI::Event<float>::Subscription> ultrasonicSubscriptions_;
	
	std::atomic<bool> isSomeIpInit_{false};

	void handleSpeedChange(const uint16_t& speed);
	void handleRPMChange(const uint16_t& rpm);
	void handleDoorStateChange(const std::vector<Perception::S_DoorState>& doorStates);
	void handleUltrasonicChange(const std::vector<Perception::S_UltrasonicState>& ultrasonicStates);

	public:
	ObservationIVIContract();
	~ObservationIVIContract();

	bool initSomeIP();

	::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::ISpeedReadings>& in_cb) override;
	::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IRPMReadings>& in_cb) override;
	::ndk::ScopedAStatus registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IUltrasonicReadings>& in_cb, int32_t in_sensorIndex) override;
	::ndk::ScopedAStatus registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IDoorStateReadings>& in_cb) override;
	::ndk::ScopedAStatus changeSystemTheme(bool in_isLightMode) override;
};
}
