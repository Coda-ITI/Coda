#include "ObservationIVIService.hpp"

using namespace aidl::android::vendor::coda;

::ndk::ScopedAStatus ObservationIVIContract::registerVehicleReadingsCallback(
   	const std::shared_ptr<IObserveVehicleReadingsCallback>& in_cb) 
{
	/*if (in_cb != nullptr)
	{
		this->mVehicleCb = in_cb;	
	}*/
	this->mVehicleCb = in_cb;
    return ::ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ObservationIVIContract::registerThemeCallback(
	const std::shared_ptr<IObserveCodaSystemThemeCallback>& in_cb) 
{
	/*if (in_cb != nullptr)
	{
		this->mThemeCb = cb;	
	}*/
	this->mThemeCb = cb;
    return ::ndk::ScopedAStatus::ok();
}
