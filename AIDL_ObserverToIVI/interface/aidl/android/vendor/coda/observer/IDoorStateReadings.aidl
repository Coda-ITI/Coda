package android.vendor.coda.observer;

//@VintfStability
interface IDoorStateReadings {
	void onDoorStateChanged(int position, boolean isOpen);
}
