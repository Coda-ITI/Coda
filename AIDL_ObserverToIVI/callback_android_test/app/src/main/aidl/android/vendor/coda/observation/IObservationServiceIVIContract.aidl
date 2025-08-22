package android.vendor.coda.observation;

import android.vendor.coda.observation.IRPMReadings;
import android.vendor.coda.observation.IDoorStateReadings;
import android.vendor.coda.observation.ISpeedReadings;
import android.vendor.coda.observation.IUltrasonicReadings;

interface IObservationServiceIVIContract {
    void registerSpeedReadingsCallback(ISpeedReadings cb);
    void registerRPMReadingsCallback(IRPMReadings cb);
    void registerUltrasonicReadingsCallback(IUltrasonicReadings cb,int sensorIndex);
    void registerDoorStateReadingsCallback(IDoorStateReadings cb);
    void changeSystemTheme(boolean isLightMode);
}
