#include "ObservationIVIService.hpp"

using aidl::android::vendor::coda::ObservationIVIContract;

int main() 
{
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "ObservationIVIService starting...");

    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<aidl::android::vendor::coda::ObservationIVIContract> observation = ndk::SharedRefBase::make<aidl::android::vendor::coda::ObservationIVIContract>();
    if (!observation) 
    {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Failed to create Bot service instance.");
        return EXIT_FAILURE;
    }
    
    const std::string instance = std::string() + aidl::android::vendor::coda::IObservationServiceIVIContract::descriptor + "/default";
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Registering service with name: %s", instance.c_str());

    binder_status_t status = AServiceManager_addService(observation->asBinder().get(), instance.c_str());

    if (status == STATUS_OK) 
    {
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Service registered successfully.");
    } 
    else 
    {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Failed to register service. Status: %d", status);
        return EXIT_FAILURE;
    }

    ABinderProcess_joinThreadPool();
    
    return EXIT_FAILURE;
}
