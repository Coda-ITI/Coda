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

namespace aidl {
namespace android {
namespace vendor {
namespace coda {
namespace observation {
class BpObservationServiceIVIContract : public ::ndk::BpCInterface<IObservationServiceIVIContract> {
public:
  explicit BpObservationServiceIVIContract(const ::ndk::SpAIBinder& binder);
  virtual ~BpObservationServiceIVIContract();

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
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace observation
}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
