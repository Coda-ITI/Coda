package android.vendor.coda.observation

import android.annotation.SuppressLint
import android.os.Bundle
import android.os.IBinder
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import java.lang.reflect.InvocationTargetException


class MainActivity : AppCompatActivity() {
    lateinit var observation : IObservationServiceIVIContract
    val TAG : String = "ServiceBinding"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        try {
            @SuppressLint("PrivateApi") val serviceManagerClass =
                Class.forName("android.os.ServiceManager")
            val getServiceMethod = serviceManagerClass.getMethod(
                "getService",
                String::class.java
            )

            val result = getServiceMethod.invoke(null, "android.vendor.coda.observation.IObservationServiceIVIContract/default")

            if (result != null) {
                val binder = result as IBinder
                observation = IObservationServiceIVIContract.Stub.asInterface(binder)
                Log.d(TAG, "Successfully bound to IObservationServiceIVIContract!")
            } else {
                Log.e(TAG, "Failed to get service binder.")
            }
        } catch (e: ClassNotFoundException) {
            Log.e(TAG, "Class not found: " + e.message)
        } catch (e: NoSuchMethodException) {
            Log.e(TAG, "Method not found: " + e.message)
        } catch (e: InvocationTargetException) {
            Log.e(TAG, "Invocation target exception: " + e.message)
        } catch (e: IllegalAccessException) {
            Log.e(TAG, "Illegal access exception: " + e.message)
        }

        if (observation != null) {
            observation.registerRPMReadingsCallback(object : IRPMReadings.Stub() {
                override fun onRpmChanged(rpm: Int) {
                    Log.d(TAG, "RPMCallback: Received RPM: $rpm")
                }
            })

            observation.registerSpeedReadingsCallback(object : ISpeedReadings.Stub() {
                override fun onSpeedChanged(speed: Int) {
                    Log.d(TAG, "SpeedCallback: Received speed: $speed")
                }
            })

            observation.registerUltrasonicReadingsCallback(object : IUltrasonicReadings.Stub() {
                override fun onUltrasonicChanged(position: Int, reading: Float) {
                    Log.d(TAG, "UltrasonicCallback: Received position and reading: $position, $reading")
                }
            }, 0)

            observation.registerDoorStateReadingsCallback(object : IDoorStateReadings.Stub() {
                override fun onDoorStateChanged(doorStates: Array<out DoorState?>?) {
                    doorStates?.forEachIndexed { index, doorState ->
                        if (doorState != null) {
                            Log.d(TAG, "Door $index -> position=${doorState.position}, isOpen=${doorState.isOpen}")
                        } else {
                            Log.d(TAG, "Door $index -> null")
                        }
                    }
                }
            })
        } else {
            Log.e(TAG, "observation is null")
        }

        observation.changeSystemTheme(true)
    }
}