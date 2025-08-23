/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 29207f876ee81063c97d9d96ee4b2984990e450a -t --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda.observation-V1-ndk-source/gen/staging/android/vendor/coda/observation/IObservationServiceIVIContract.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda.observation-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda.observation-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda.observation/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda.observation/1/android/vendor/coda/observation/IObservationServiceIVIContract.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/vendor/coda/observation/IObservationServiceIVIContract.h"

#include <android/binder_ibinder.h>
#include <cassert>

#ifndef __BIONIC__
#ifndef __assert2
#define __assert2(a,b,c,d) ((void)0)
#endif
#endif

namespace aidl {
namespace android {
namespace vendor {
namespace coda {
namespace observation {
class BnObservationServiceIVIContract : public ::ndk::BnCInterface<IObservationServiceIVIContract> {
public:
  BnObservationServiceIVIContract();
  virtual ~BnObservationServiceIVIContract();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IObservationServiceIVIContractDelegator : public BnObservationServiceIVIContract {
public:
  explicit IObservationServiceIVIContractDelegator(const std::shared_ptr<IObservationServiceIVIContract> &impl) : _impl(impl) {
     int32_t _impl_ver = 0;
     if (!impl->getInterfaceVersion(&_impl_ver).isOk()) {;
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Delegator failed to get version of the implementation.");
     }
     if (_impl_ver != IObservationServiceIVIContract::version) {
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Mismatched versions of delegator and implementation is not allowed.");
     }
  }

  ::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::ISpeedReadings>& in_cb) override {
    return _impl->registerSpeedReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IRPMReadings>& in_cb) override {
    return _impl->registerRPMReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus registerUltrasonic0ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) override {
    return _impl->registerUltrasonic0ReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus registerUltrasonic1ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) override {
    return _impl->registerUltrasonic1ReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus registerUltrasonic2ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) override {
    return _impl->registerUltrasonic2ReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus registerUltrasonic3ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) override {
    return _impl->registerUltrasonic3ReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus registerDoorStateFLReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) override {
    return _impl->registerDoorStateFLReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus registerDoorStateFRReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) override {
    return _impl->registerDoorStateFRReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus registerDoorStateRLReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) override {
    return _impl->registerDoorStateRLReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus registerDoorStateRRReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) override {
    return _impl->registerDoorStateRRReadingsCallback(in_cb);
  }
  ::ndk::ScopedAStatus changeSystemThemeToLight() override {
    return _impl->changeSystemThemeToLight();
  }
  ::ndk::ScopedAStatus changeSystemThemeToDark() override {
    return _impl->changeSystemThemeToDark();
  }
protected:
private:
  std::shared_ptr<IObservationServiceIVIContract> _impl;
};

}  // namespace observation
}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
