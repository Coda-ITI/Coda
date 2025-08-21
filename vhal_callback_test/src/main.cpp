#include <aidl/android/hardware/automotive/vehicle/IVehicle.h>
#include <aidl/android/hardware/automotive/vehicle/BnVehicleCallback.h>
#include <aidl/android/hardware/automotive/vehicle/GetValueRequest.h>
#include <aidl/android/hardware/automotive/vehicle/GetValueResults.h>
#include <aidl/android/hardware/automotive/vehicle/SetValueRequest.h>
#include <aidl/android/hardware/automotive/vehicle/SetValueRequests.h>
#include <aidl/android/hardware/automotive/vehicle/SetValueResults.h>
#include <aidl/android/hardware/automotive/vehicle/VehiclePropValue.h>
#include <aidl/android/hardware/automotive/vehicle/VehiclePropValues.h>
#include <aidl/android/hardware/automotive/vehicle/VehiclePropError.h>
#include <aidl/android/hardware/automotive/vehicle/VehiclePropErrors.h>

#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <utils/Log.h>  // for ALOGI/ALOGE

using ::aidl::android::hardware::automotive::vehicle::IVehicle;
using ::aidl::android::hardware::automotive::vehicle::BnVehicleCallback;
using ::aidl::android::hardware::automotive::vehicle::GetValueResults;
using ::aidl::android::hardware::automotive::vehicle::SetValueResults;
using ::aidl::android::hardware::automotive::vehicle::SetValueRequests;
using ::aidl::android::hardware::automotive::vehicle::SetValueRequest;
using ::aidl::android::hardware::automotive::vehicle::VehiclePropValue;
using ::aidl::android::hardware::automotive::vehicle::VehiclePropValues;
using ::aidl::android::hardware::automotive::vehicle::VehiclePropErrors;

class MyVehicleCallback final : public BnVehicleCallback {
public:
    ndk::ScopedAStatus onGetValues(const GetValueResults& results) override {
        const auto& vec = results.payloads;
        for (const auto& r : vec) {
            if (r.prop.has_value()) {
                ALOGI("onGetValues: status=%d, propId=0x%x",
                      (int)r.status, r.prop->prop);
            } else {
                ALOGI("onGetValues: status=%d, (no prop returned)", (int)r.status);
            }
        }
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus onSetValues(const SetValueResults& results) override {
        const auto& vec = results.payloads;
        for (const auto& r : vec) {
            ALOGI("onSetValues: status=%d", (int)r.status);
        }
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus onPropertyEvent(const VehiclePropValues& values,
                                       int32_t /*sharedMemoryFileCount*/) override {
        const auto& vec = values.payloads;
        for (const auto& v : vec) {
            ALOGI("onPropertyEvent: propId=0x%x, timestamp=%lld",
                  v.prop, (long long)v.timestamp);
        }
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus onPropertySetError(const VehiclePropErrors& errors) override {
        const auto& vec = errors.payloads;
        for (const auto& e : vec) {
            ALOGE("onPropertySetError: propId=0x%x, status=%d",
                  e.propId, (int)e.errorCode);
        }
        return ndk::ScopedAStatus::ok();
    }
};

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(0);

    // Get the VHAL service
    ::ndk::SpAIBinder binder(AServiceManager_waitForService(
        (std::string(IVehicle::descriptor) + "/default").c_str()));
    if (!binder.get()) {
        ALOGE("Failed to get IVehicle service");
        return 1;
    }

    std::shared_ptr<IVehicle> vehicle = IVehicle::fromBinder(binder);
    if (!vehicle) {
        ALOGE("Failed to cast binder to IVehicle");
        return 1;
    }

    auto cb = ndk::SharedRefBase::make<MyVehicleCallback>();

    // Build a SetValueRequests wrapper and push a single SetValueRequest
    SetValueRequests setReqs;
    SetValueRequest req{};
    VehiclePropValue v{};
    // dec = 557846324
    v.prop = 0x0F34 + 0x20000000 + 0x01000000 + 0x00400000;
    v.value.int32Values = {1};
    req.value = v;
    setReqs.payloads.push_back(req);

    auto st = vehicle->setValues(cb, setReqs);
    if (!st.isOk()) {
        ALOGE("setValues transaction failed: %s", st.getDescription().c_str());
        return 1;
    }

    ABinderProcess_joinThreadPool();
    return 0;
}

