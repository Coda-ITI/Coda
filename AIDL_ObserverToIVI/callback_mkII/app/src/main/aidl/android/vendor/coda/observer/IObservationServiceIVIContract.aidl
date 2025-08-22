package android.vendor.coda.observer;

import android.vendor.coda.observer.IRPMReadings;
import android.vendor.coda.observer.IDoorStateReadings;
import android.vendor.coda.observer.ISpeedReadings;
import android.vendor.coda.observer.IUltrasonicReadings;

interface IObservationServiceIVIContract {
    void registerSpeedReadingsCallback(ISpeedReadings cb);
    void registerRPMReadingsCallback(IRPMReadings cb);
    void registerUltrasonicReadingsCallback(IUltrasonicReadings cb);
    void registerDoorStateReadingsCallback(IDoorStateReadings cb);
    void changeSystemTheme(boolean isLightMode);
}