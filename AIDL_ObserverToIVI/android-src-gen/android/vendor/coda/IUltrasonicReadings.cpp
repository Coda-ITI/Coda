/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 7c1f61b90e5145a5ab046d4ff434cc1a6d5eed97 -t --stability vintf --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging/android/vendor/coda/IUltrasonicReadings.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1/android/vendor/coda/IUltrasonicReadings.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#include "aidl/android/vendor/coda/IUltrasonicReadings.h"

#include <android/binder_parcel_utils.h>
#include <aidl/android/vendor/coda/BnUltrasonicReadings.h>
#include <aidl/android/vendor/coda/BpUltrasonicReadings.h>

namespace aidl {
namespace android {
namespace vendor {
namespace coda {
static binder_status_t _aidl_android_vendor_coda_IUltrasonicReadings_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnUltrasonicReadings> _aidl_impl = std::static_pointer_cast<BnUltrasonicReadings>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onUltrasonicChanged*/): {
      int32_t in_position;
      float in_reading;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_position);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_reading);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onUltrasonicChanged(in_position, in_reading);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 16777214 /*getInterfaceVersion*/): {
      int32_t _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceVersion(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 16777213 /*getInterfaceHash*/): {
      std::string _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceHash(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static const char* _g_aidl_android_vendor_coda_IUltrasonicReadings_clazz_code_to_function[] = { "onUltrasonicChanged",};
static AIBinder_Class* _g_aidl_android_vendor_coda_IUltrasonicReadings_clazz = ::ndk::ICInterface::defineClass(IUltrasonicReadings::descriptor, _aidl_android_vendor_coda_IUltrasonicReadings_onTransact, _g_aidl_android_vendor_coda_IUltrasonicReadings_clazz_code_to_function, 1);

BpUltrasonicReadings::BpUltrasonicReadings(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpUltrasonicReadings::~BpUltrasonicReadings() {}

::ndk::ScopedAStatus BpUltrasonicReadings::onUltrasonicChanged(int32_t in_position, float in_reading) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinderReference().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_position);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_reading);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinderReference().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onUltrasonicChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | static_cast<int>(FLAG_PRIVATE_LOCAL)
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IUltrasonicReadings::getDefaultImpl()) {
    _aidl_status = IUltrasonicReadings::getDefaultImpl()->onUltrasonicChanged(in_position, in_reading);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpUltrasonicReadings::getInterfaceVersion(int32_t* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  if (_aidl_cached_version != -1) {
    *_aidl_return = _aidl_cached_version;
    _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
    return _aidl_status;
  }
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinderReference().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinderReference().get(),
    (FIRST_CALL_TRANSACTION + 16777214 /*getInterfaceVersion*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | static_cast<int>(FLAG_PRIVATE_LOCAL)
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IUltrasonicReadings::getDefaultImpl()) {
    _aidl_status = IUltrasonicReadings::getDefaultImpl()->getInterfaceVersion(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_cached_version = *_aidl_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpUltrasonicReadings::getInterfaceHash(std::string* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  const std::lock_guard<std::mutex> lock(_aidl_cached_hash_mutex);
  if (_aidl_cached_hash != "-1") {
    *_aidl_return = _aidl_cached_hash;
    _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
    return _aidl_status;
  }
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinderReference().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinderReference().get(),
    (FIRST_CALL_TRANSACTION + 16777213 /*getInterfaceHash*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | static_cast<int>(FLAG_PRIVATE_LOCAL)
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IUltrasonicReadings::getDefaultImpl()) {
    _aidl_status = IUltrasonicReadings::getDefaultImpl()->getInterfaceHash(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_cached_hash = *_aidl_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnUltrasonicReadings
BnUltrasonicReadings::BnUltrasonicReadings() {}
BnUltrasonicReadings::~BnUltrasonicReadings() {}
::ndk::SpAIBinder BnUltrasonicReadings::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_android_vendor_coda_IUltrasonicReadings_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markVintfStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
::ndk::ScopedAStatus BnUltrasonicReadings::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = IUltrasonicReadings::version;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus BnUltrasonicReadings::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = IUltrasonicReadings::hash;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
// Source for IUltrasonicReadings
const char* IUltrasonicReadings::descriptor = "android.vendor.coda.IUltrasonicReadings";
IUltrasonicReadings::IUltrasonicReadings() {}
IUltrasonicReadings::~IUltrasonicReadings() {}


std::shared_ptr<IUltrasonicReadings> IUltrasonicReadings::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_android_vendor_coda_IUltrasonicReadings_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<BpUltrasonicReadings>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IUltrasonicReadings>(interface);
  }
  return ::ndk::SharedRefBase::make<BpUltrasonicReadings>(binder);
}

binder_status_t IUltrasonicReadings::writeToParcel(AParcel* parcel, const std::shared_ptr<IUltrasonicReadings>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IUltrasonicReadings::readFromParcel(const AParcel* parcel, std::shared_ptr<IUltrasonicReadings>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IUltrasonicReadings::fromBinder(binder);
  return STATUS_OK;
}
bool IUltrasonicReadings::setDefaultImpl(const std::shared_ptr<IUltrasonicReadings>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IUltrasonicReadings::default_impl);
  if (impl) {
    IUltrasonicReadings::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IUltrasonicReadings>& IUltrasonicReadings::getDefaultImpl() {
  return IUltrasonicReadings::default_impl;
}
std::shared_ptr<IUltrasonicReadings> IUltrasonicReadings::default_impl = nullptr;
::ndk::ScopedAStatus IUltrasonicReadingsDefault::onUltrasonicChanged(int32_t /*in_position*/, float /*in_reading*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IUltrasonicReadingsDefault::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = 0;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus IUltrasonicReadingsDefault::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = "";
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::SpAIBinder IUltrasonicReadingsDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IUltrasonicReadingsDefault::isRemote() {
  return false;
}
}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
