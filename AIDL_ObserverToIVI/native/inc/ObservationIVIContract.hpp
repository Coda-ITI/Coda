#pragma once

#include <aidl/android/vendor/coda/BnObservationIVIContract.h>
#include <aidl/android/vendor/coda/IObserveVehicleReadingsCallback.h>
#include <aidl/android/vendor/coda/IObserveCodaSystemThemeCallback.h>
#include <android/binder_ibinder.h>
#include <iostream>
#include <android/log.h>

// using ::android::sp;

using namespace aidl::android::vendor::coda;

class ObservationIVIContract : public aidl::android::vendor::coda::BnObservationIVIContract {
	private:
    	std::shared_ptr<IObserveVehicleReadingsCallback> mVehicleCb;
    	std::shared_ptr<IObserveCodaSystemThemeCallback> mThemeCb;
    
	public:
		::ndk::ScopedAStatus registerVehicleReadingsCallback(
   			const std::shared_ptr<IObserveVehicleReadingsCallback>& in_cb) override;

		::ndk::ScopedAStatus registerThemeCallback(
   			const std::shared_ptr<IObserveCodaSystemThemeCallback>& in_cb) override;
};

