/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 29207f876ee81063c97d9d96ee4b2984990e450a -t --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda.observation-V1-ndk-source/gen/staging/android/vendor/coda/observation/ISpeedReadings.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda.observation-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda.observation-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda.observation/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda.observation/1/android/vendor/coda/observation/ISpeedReadings.aidl
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
namespace observation {
class ISpeedReadingsDelegator;

class ISpeedReadings : public ::ndk::ICInterface {
public:
  typedef ISpeedReadingsDelegator DefaultDelegator;
  static const char* descriptor;
  ISpeedReadings();
  virtual ~ISpeedReadings();

  static inline const int32_t version = 1;
  static inline const std::string hash = "29207f876ee81063c97d9d96ee4b2984990e450a";
  static constexpr uint32_t TRANSACTION_onSpeedChanged = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<ISpeedReadings> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ISpeedReadings>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ISpeedReadings>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ISpeedReadings>& impl);
  static const std::shared_ptr<ISpeedReadings>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onSpeedChanged(int32_t in_speed) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<ISpeedReadings> default_impl;
};
class ISpeedReadingsDefault : public ISpeedReadings {
public:
  ::ndk::ScopedAStatus onSpeedChanged(int32_t in_speed) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace observation
}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
