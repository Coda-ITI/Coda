package android.vendor.coda.observer;

interface IUltrasonicReadings {
    void onUltrasonicChanged(int position, float reading);
}