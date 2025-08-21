PRODUCT_PACKAGES += libambientlight ObservationServiceApp 

PRODUCT_COPY_FILES += \
		vendor/Coda/init_hw/init.codahw.rc:root/init.codahw.rc 
#		vendor/Coda/evs_config/evs_configuration_override.xml:$(TARGET_COPY_OUT_VENDOR)/etc/automotive/evs/evs_configuration_override.xml \
	        #vendor/Coda/static_ip/init.staticip.rc:root/init.staticip.rc \
		
#PRODUCT_PACKAGES += \
#	VoiceInteraction 

#         vendor/Avalon/init.driverlauncher.rc:root/init.driverlauncher.rc \
# MultiDisplaySecondaryHomeTestLauncher DriverLauncher

# PRODUCT_COPY_FILES += vendor/Avalon/init.avalonhw.rc:root/init.avalonhw.rc vendor/Avalon/MUMD/InputPortAssociation/input-port-associations.xml:$(TARGET_COPY_OUT_VENDOR)/etc/input-port-associations.xml

# BOARD_SEPOLICY_DIRS += vendor/Avalon/GPS/sepolicy 
