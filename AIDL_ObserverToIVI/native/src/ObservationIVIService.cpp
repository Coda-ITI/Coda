#include "ObservationIVIService.hpp"

::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::ISpeedReadings>& in_cb) 
{
	this->mSpeedValCb = in_cb;
	if (in_cb != nullptr)
	{
		std::cout << "speed callback registered successfully" << std::endl;
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IRPMReadings>& in_cb) 
{
	this->mRPMValCb = in_cb;
	if (in_cb != nullptr)
	{
		std::cout << "rpm callback registered successfully" << std::endl;
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IUltrasonicReadings>& in_cb) 
{
	this->mUltrasonicReadingCb = in_cb;
	if (in_cb != nullptr)
	{
		std::cout << "ultrasonic callback registered successfully" << std::endl;
	}
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IDoorStateReadings>& in_cb) 
{
	/*if (in_cb != nullptr)
	{
		this->mVehicleCb = in_cb;	
	}*/
	this->mDoorStateCb = in_cb;
	if (in_cb != nullptr)
	{
		std::cout << "door state callback registered successfully" << std::endl;
	}
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus changeSystemTheme(bool in_isLightMode) 
{
	std::cout << "received a flag of value " << in_isLightMode << " to change the system them" << std::endl;
	// notify->changeTheme() /** using IVI stub */
    return ::ndk::ScopedAStatus::ok();
}

