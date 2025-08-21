#include "ObservationIVIService.hpp"

using namespace aidl::android::vendor::coda;

::ndk::ScopedAStatus registerSpeedReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::ISpeedReadings>& in_cb) 
{
	this->mSpeedValCb = in_cb;
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus registerRPMReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IRPMReadings>& in_cb) 
{
	this->mRPMValCb = in_cb;
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus registerUltrasonicReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IUltrasonicReadings>& in_cb) 
{
	this->mUltrasonicReadingCb = in_cb;
	return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus registerDoorStateReadingsCallback(const std::shared_ptr<::aidl::android::vendor::coda::IDoorStateReadings>& in_cb) 
{
	/*if (in_cb != nullptr)
	{
		this->mVehicleCb = in_cb;	
	}*/
	this->mDoorStateCb = in_cb;
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus changeSystemTheme(bool in_isLightMode) 
{
	// notify->changeTheme() /** using IVI stub */
    return ::ndk::ScopedAStatus::ok();
}

