package android.vendor.coda;
import android.vendor.coda.DoorState;

@VintfStability
interface IDoorStateReadings {
	void onDoorStateChanged(in DoorState[] doorStates);
}
