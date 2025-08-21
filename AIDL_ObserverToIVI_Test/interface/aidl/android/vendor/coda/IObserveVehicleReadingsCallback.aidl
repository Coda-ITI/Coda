package android.vendor.coda;

@VintfStability
interface IObserveVehicleReadingsCallback {
    void onSpeedChanged(int speed);
    void onRpmChanged(int rpm);
    void onDoorStateChanged(int position, boolean isOpen);
    void onUltrasonicChanged(int position, float reading);
}
