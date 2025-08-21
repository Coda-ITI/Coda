package android.vendor.coda;

@VintfStability
interface IUltrasonicReadings {
    void onUltrasonicChanged(int position, float reading);
}
