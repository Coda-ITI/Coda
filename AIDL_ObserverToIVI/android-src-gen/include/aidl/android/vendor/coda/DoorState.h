/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash 7c1f61b90e5145a5ab046d4ff434cc1a6d5eed97 -t --stability vintf --min_sdk_version current --ninja -d out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging/android/vendor/coda/DoorState.cpp.d -h out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/vendor/Coda/AIDL_ObserverToIVI/interface/aidl/android.vendor.coda-V1-ndk-source/gen/staging -Nvendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1 vendor/Coda/AIDL_ObserverToIVI/interface/aidl/aidl_api/android.vendor.coda/1/android/vendor/coda/DoorState.aidl
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
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace vendor {
namespace coda {
class DoorState {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t position = 0;
  bool isOpen = false;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const DoorState& _rhs) const {
    return std::tie(position, isOpen) == std::tie(_rhs.position, _rhs.isOpen);
  }
  inline bool operator<(const DoorState& _rhs) const {
    return std::tie(position, isOpen) < std::tie(_rhs.position, _rhs.isOpen);
  }
  inline bool operator!=(const DoorState& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const DoorState& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const DoorState& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const DoorState& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "DoorState{";
    _aidl_os << "position: " << ::android::internal::ToString(position);
    _aidl_os << ", isOpen: " << ::android::internal::ToString(isOpen);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace coda
}  // namespace vendor
}  // namespace android
}  // namespace aidl
