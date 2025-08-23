/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 7c1f61b90e5145a5ab046d4ff434cc1a6d5eed97 -t --stability vintf --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging/android/vendor/coda/IObservationServiceIVIContract.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1/android/vendor/coda/IObservationServiceIVIContract.aidl
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
#include <aidl/android/vendor/coda/IDoorStateReadings.h>
#include <aidl/android/vendor/coda/IRPMReadings.h>
#include <aidl/android/vendor/coda/ISpeedReadings.h>
#include <aidl/android/vendor/coda/IUltrasonicReadings.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::vendor::coda {
class IDoorStateReadings;
class IRPMReadings;
class ISpeedReadings;
class IUltrasonicReadings;
}  // namespace aidl::android::vendor::coda
namespace aidl {
namespace android {
namespace vendor {
namespace coda {
class IObservationServiceIVIContractDelegator;

class IObservationServiceIVIContract : public ::ndk::ICInterface {
public:
  typedef IObservationServiceIVIContractDelegator DefaultDelegator;
  static const char* descriptor;
  IObservationServiceIVIContract();
  virtual ~IObservationServiceIVIContract();

  static inline const int32_t version = 1;
  static inline const std::string hash = "7c1f61b90e5145a5ab046d4ff434cc1a6d5eed97";
  static constexpr uint32_t TRANSACTION_registerSpeedReadingsCallback = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_registerRPMReadingsCallback = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_registerUltrasonicReadingsCallback = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_registerDoorStateReadingsCallback = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_changeSystemTheme = FIRST_CALL_TRANSACTION + 4;

  static std::shared_ptr<IObservationServiceIVIContract> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IObservationServiceIVIContract>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IObservationServiceIVIContract>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IObservationServiceIVIContract>& impl);
  static const std::shared_ptr<IObservationServiceIVIContract>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::ISpeedReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IRPMReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IUltrasonicReadings>& in_cb, int32_t in_sensorIndex) = 0;
  virtual ::ndk::ScopedAStatus registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IDoorStateReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus changeSystemTheme(bool in_isLightMode) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IObservationServiceIVIContract> default_impl;
};
class IObservationServiceIVIContractDefault : public IObservationServiceIVIContract {
public:
  ::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::ISpeedReadings>& in_cb) override;
  ::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IRPMReadings>& in_cb) override;
  ::ndk::ScopedAStatus registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IUltrasonicReadings>& in_cb, int32_t in_sensorIndex) override;
  ::ndk::ScopedAStatus registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IDoorStateReadings>& in_cb) override;
  ::ndk::ScopedAStatus changeSystemTheme(bool in_isLightMode) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
