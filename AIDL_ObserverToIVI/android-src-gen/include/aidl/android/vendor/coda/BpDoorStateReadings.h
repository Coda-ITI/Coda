/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 7c1f61b90e5145a5ab046d4ff434cc1a6d5eed97 -t --stability vintf --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging/android/vendor/coda/IDoorStateReadings.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1/android/vendor/coda/IDoorStateReadings.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/vendor/coda/IDoorStateReadings.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace vendor {
namespace coda {
class BpDoorStateReadings : public ::ndk::BpCInterface<IDoorStateReadings> {
public:
  explicit BpDoorStateReadings(const ::ndk::SpAIBinder& binder);
  virtual ~BpDoorStateReadings();

  ::ndk::ScopedAStatus onDoorStateChanged(const std::vector<::aidl::android::vendor::coda::DoorState>& in_doorStates) override;
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
