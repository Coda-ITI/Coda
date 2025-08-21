#include "ObservationIVIService.hpp"

int main() 
{

    std::cout << "ObservationIVIService starting..." << std::endl;

    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<ObservationIVIService> observation = ndk::SharedRefBase::make<ObservationIVIService>();
    if (!observation) 
    {
        std::cout << "Failed to create Bot service instance." << std::endl;
        return EXIT_FAILURE;
    }
    
    const std::string instance = std::string() + IObservationIVIService::descriptor + "/default";
    std::cout << "Registering service with name: " << instance << std::endl;

    binder_status_t status = AServiceManager_addService(observation->asBinder().get(), instance.c_str());

    if (status == STATUS_OK) {
        std::cout << "Service registered successfully." << std::endl;
    } else {
        std::cout << "Failed to register service. Status: " << status << std::endl;
        return EXIT_FAILURE;
    }

    ABinderProcess_joinThreadPool();
    
    return EXIT_FAILURE;
}
