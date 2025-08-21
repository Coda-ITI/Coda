package android.vendor.coda;

import android.vendor.coda.IObserveVehicleReadingsCallback;
import android.vendor.coda.IObserveCodaSystemThemeCallback;

@VintfStability
interface IObservationIVIContract {
    void registerVehicleReadingsCallback(IObserveVehicleReadingsCallback cb);
    void registerThemeCallback(IObserveCodaSystemThemeCallback cb);
}
