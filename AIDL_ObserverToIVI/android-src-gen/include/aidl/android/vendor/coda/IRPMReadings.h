/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 7c1f61b90e5145a5ab046d4ff434cc1a6d5eed97 -t --stability vintf --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging/android/vendor/coda/IRPMReadings.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1/android/vendor/coda/IRPMReadings.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace vendor {
namespace coda {
class IRPMReadingsDelegator;

class IRPMReadings : public ::ndk::ICInterface {
public:
  typedef IRPMReadingsDelegator DefaultDelegator;
  static const char* descriptor;
  IRPMReadings();
  virtual ~IRPMReadings();

  static inline const int32_t version = 1;
  static inline const std::string hash = "7c1f61b90e5145a5ab046d4ff434cc1a6d5eed97";
  static constexpr uint32_t TRANSACTION_onRpmChanged = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<IRPMReadings> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IRPMReadings>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IRPMReadings>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IRPMReadings>& impl);
  static const std::shared_ptr<IRPMReadings>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onRpmChanged(int32_t in_rpm) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IRPMReadings> default_impl;
};
class IRPMReadingsDefault : public IRPMReadings {
public:
  ::ndk::ScopedAStatus onRpmChanged(int32_t in_rpm) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
