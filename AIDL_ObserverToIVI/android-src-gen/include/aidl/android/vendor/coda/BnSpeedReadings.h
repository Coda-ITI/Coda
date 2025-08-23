/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 7c1f61b90e5145a5ab046d4ff434cc1a6d5eed97 -t --stability vintf --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging/android/vendor/coda/ISpeedReadings.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1/android/vendor/coda/ISpeedReadings.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/vendor/coda/ISpeedReadings.h"

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
class BnSpeedReadings : public ::ndk::BnCInterface<ISpeedReadings> {
public:
  BnSpeedReadings();
  virtual ~BnSpeedReadings();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class ISpeedReadingsDelegator : public BnSpeedReadings {
public:
  explicit ISpeedReadingsDelegator(const std::shared_ptr<ISpeedReadings> &impl) : _impl(impl) {
     int32_t _impl_ver = 0;
     if (!impl->getInterfaceVersion(&_impl_ver).isOk()) {;
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Delegator failed to get version of the implementation.");
     }
     if (_impl_ver != ISpeedReadings::version) {
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Mismatched versions of delegator and implementation is not allowed.");
     }
  }

  ::ndk::ScopedAStatus onSpeedChanged(int32_t in_speed) override {
    return _impl->onSpeedChanged(in_speed);
  }
protected:
private:
  std::shared_ptr<ISpeedReadings> _impl;
};

}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
