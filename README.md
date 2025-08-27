# Coda

## Introduction
This is the Android Automotive vendor package for Coda: it contains all the configurations, libraries, and apps needed for Coda's IVI Node to function as intended.

The vendor package has only been tested on Raspberry Pi 5; if you plan on using it on another SBC, functionality is not guaranteed.

## Content
1. Observation Service: this is the backbone of the IVI as it is responsible for receiving car info/readings, send these readings to the application layer to display them for the driver, and publish an event for theme change to make it system-wide (reflect on Cluster Node as well)
2. Coda-IVI Runtime Resource Overlay (RRO) For Light Mode.
3. Boot Scripts For HW Initializations.
4. Custom Library For Ambient Light Control.
