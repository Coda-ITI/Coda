#include "led.hpp"
#include "gpiohal.hpp"

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <android/binder_ibinder.h>
#include <aidl/android/vendor/gpio/IGpioService.h> 

#define LED_PIN 17
#define HIGH 1
#define LOW 0

using aidl::android::vendor::gpio::GpioService;

int main() {

    LOG(INFO) << "Bot_service starting...";

    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<aidl::android::vendor::gpio::GpioService> led = ndk::SharedRefBase::make<aidl::android::vendor::gpio::GpioService>();
     if (!led) {
        LOG(ERROR) << "Failed to create Bot service instance.";
        return EXIT_FAILURE;
    }
    const std::string instance = std::string() + aidl::android::vendor::gpio::IGpioService::descriptor + "/default";
    LOG(INFO) << "Registering service with name: " << instance;

    
    
    binder_status_t status = AServiceManager_addService(led->asBinder().get(), instance.c_str());

        if (status == STATUS_OK) {
            LOG(INFO) << "Service registered successfully.";
        } else {
            LOG(ERROR) << "Failed to register service. Status: " << status;
            return EXIT_FAILURE;
        }
        ABinderProcess_joinThreadPool();
        return EXIT_FAILURE;
}
