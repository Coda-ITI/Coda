#include <aidl/android/hardware/automotive/vehicle/IVehicle.h>
#include <aidl/android/hardware/automotive/vehicle/VehiclePropValue.h>
#include <aidl/android/hardware/automotive/vehicle/VehicleProperty.h>
#include <aidl/android/hardware/automotive/vehicle/VehiclePropertyStatus.h>

#include <android/binder_manager.h>
#include <android/binder_process.h>

using ::aidl::android::hardware::automotive::vehicle::IVehicle;
using ::aidl::android::hardware::automotive::vehicle::VehiclePropValue;
using ::aidl::android::hardware::automotive::vehicle::VehicleProperty;
using ::aidl::android::hardware::automotive::vehicle::VehiclePropertyStatus;

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(1);

    ndk::SpAIBinder binder(AServiceManager_waitForService(
        "android.hardware.automotive.vehicle.IVehicle/default"));
    if (!AIBinder_isAlive(binder.get())) {
        //LOG(ERROR) << "Failed to get VHAL service";
        return 1;
    }

    std::shared_ptr<IVehicle> vhal = IVehicle::fromBinder(binder);
    if (!vhal) {
        //LOG(ERROR) << "Failed to cast binder to IVehicle";
        return 1;
    }

    VehiclePropValue value;
    value.prop = static_cast<int32_t>(VehicleProperty::HVAC_FAN_SPEED);
    value.areaId = 0;
    value.status = VehiclePropertyStatus::AVAILABLE;
    value.value.int32Values = {3};

    std::vector<VehiclePropValue> values = { value };
    auto status = vhal->setValues(values);
    if (!status.isOk()) {
        //LOG(ERROR) << "setValues() failed: " << status.getDescription();
        return 1;
    }

    std::cout << "Successfully set HVAC_FAN_SPEED = 3";
    return 0;
}

