package android.vendor.coda;

@VintfStability
interface IDoorStateReadings {
	void onDoorStateChanged(int position, boolean isOpen);
}
