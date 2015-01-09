# Geos Simple Demo App #

This project contains simple iOS Application demonstrates how to use [ifinitySDK](https://github.com/Ifinity/ifinity-ios-sdk)

To compile app you must obtain _application id_ and _application secret_ first. To do this register or login on [http://geos.zone](http://geos.zone). Credentials should be set in ``GEOS_APP_ID`` and ``GEOS_SECRET``  constraints in ```ApplicationDelegate.m``` file.



*Advice* 
Sometimes app may crash. This happens when you run latest app over version 1.0. It is caused by CoreData model version migration magic. In this case helps deleting old app from device/simulator.