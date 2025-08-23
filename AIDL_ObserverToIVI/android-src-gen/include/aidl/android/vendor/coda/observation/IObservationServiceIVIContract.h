/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 29207f876ee81063c97d9d96ee4b2984990e450a -t --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda.observation-V1-ndk-source/gen/staging/android/vendor/coda/observation/IObservationServiceIVIContract.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda.observation-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda.observation-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda.observation/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda.observation/1/android/vendor/coda/observation/IObservationServiceIVIContract.aidl
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
#include <aidl/android/vendor/coda/observation/IDoorStateReadings.h>
#include <aidl/android/vendor/coda/observation/IRPMReadings.h>
#include <aidl/android/vendor/coda/observation/ISpeedReadings.h>
#include <aidl/android/vendor/coda/observation/IUltrasonicReadings.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::vendor::coda::observation {
class IDoorStateReadings;
class IRPMReadings;
class ISpeedReadings;
class IUltrasonicReadings;
}  // namespace aidl::android::vendor::coda::observation
namespace aidl {
namespace android {
namespace vendor {
namespace coda {
namespace observation {
class IObservationServiceIVIContractDelegator;

class IObservationServiceIVIContract : public ::ndk::ICInterface {
public:
  typedef IObservationServiceIVIContractDelegator DefaultDelegator;
  static const char* descriptor;
  IObservationServiceIVIContract();
  virtual ~IObservationServiceIVIContract();

  static inline const int32_t version = 1;
  static inline const std::string hash = "29207f876ee81063c97d9d96ee4b2984990e450a";
  static constexpr uint32_t TRANSACTION_registerSpeedReadingsCallback = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_registerRPMReadingsCallback = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_registerUltrasonic0ReadingsCallback = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_registerUltrasonic1ReadingsCallback = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_registerUltrasonic2ReadingsCallback = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_registerUltrasonic3ReadingsCallback = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_registerDoorStateFLReadingsCallback = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_registerDoorStateFRReadingsCallback = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_registerDoorStateRLReadingsCallback = FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_registerDoorStateRRReadingsCallback = FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_changeSystemThemeToLight = FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_changeSystemThemeToDark = FIRST_CALL_TRANSACTION + 11;

  static std::shared_ptr<IObservationServiceIVIContract> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IObservationServiceIVIContract>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IObservationServiceIVIContract>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IObservationServiceIVIContract>& impl);
  static const std::shared_ptr<IObservationServiceIVIContract>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::ISpeedReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IRPMReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerUltrasonic0ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerUltrasonic1ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerUltrasonic2ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerUltrasonic3ReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IUltrasonicReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerDoorStateFLReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerDoorStateFRReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerDoorStateRLReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus registerDoorStateRRReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::observation::IDoorStateReadings>& in_cb) = 0;
  virtual ::ndk::ScopedAStatus changeSystemThemeToLight() = 0;
  virtual ::ndk::ScopedAStatus changeSystemThemeToDark() = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IObservationServiceIVIContract> default_impl;
};
class IObservationServiceIVIContractDefault : public IObservationServiceIVIContract {
public:
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
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace observation
}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
