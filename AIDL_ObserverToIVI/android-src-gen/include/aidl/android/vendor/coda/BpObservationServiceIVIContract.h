/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 7c1f61b90e5145a5ab046d4ff434cc1a6d5eed97 -t --stability vintf --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging/android/vendor/coda/IObservationServiceIVIContract.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1/android/vendor/coda/IObservationServiceIVIContract.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/vendor/coda/IObservationServiceIVIContract.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace vendor {
namespace coda {
class BpObservationServiceIVIContract : public ::ndk::BpCInterface<IObservationServiceIVIContract> {
public:
  explicit BpObservationServiceIVIContract(const ::ndk::SpAIBinder& binder);
  virtual ~BpObservationServiceIVIContract();

  ::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::ISpeedReadings>& in_cb) override;
  ::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IRPMReadings>& in_cb) override;
  ::ndk::ScopedAStatus registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IUltrasonicReadings>& in_cb, int32_t in_sensorIndex) override;
  ::ndk::ScopedAStatus registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IDoorStateReadings>& in_cb) override;
  ::ndk::ScopedAStatus changeSystemTheme(bool in_isLightMode) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
