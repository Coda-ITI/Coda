package android.vendor.coda.observation;
import android.vendor.coda.observation.DoorState;

interface IDoorStateReadings {
	void onDoorStateChanged(in DoorState[] doorStates);
}
