package android.vendor.coda.observer;

interface IDoorStateReadings {
	void onDoorStateChanged(int position, boolean isOpen);
}