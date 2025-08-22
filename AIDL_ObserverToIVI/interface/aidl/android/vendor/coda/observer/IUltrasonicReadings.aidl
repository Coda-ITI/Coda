package android.vendor.coda.observer;

//@VintfStability
interface IUltrasonicReadings {
    void onUltrasonicChanged(int position, float reading);
}
