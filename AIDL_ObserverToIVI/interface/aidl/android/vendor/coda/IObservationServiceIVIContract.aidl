package android.vendor.coda;

import android.vendor.coda.IRPMReadings;
import android.vendor.coda.IDoorStateReadings;
import android.vendor.coda.ISpeedReadings;
import android.vendor.coda.IUltrasonicReadings;

@VintfStability
interface IObservationServiceIVIContract {
    void registerSpeedReadingsCallback(ISpeedReadings cb);
    void registerRPMReadingsCallback(IRPMReadings cb);
    void registerUltrasonicReadingsCallback(IUltrasonicReadings cb,int sensorIndex);
    void registerDoorStateReadingsCallback(IDoorStateReadings cb);
    void changeSystemTheme(boolean isLightMode);
}
