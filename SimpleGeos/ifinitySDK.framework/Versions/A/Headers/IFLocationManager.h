//
//  IFPositionManager.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 04.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MKMapView.h>

@class IFLocationManager;

/**
 *  Delegate for `IFLocationManager` class.
 */
@protocol IFLocationManagerDelegate <NSObject>
@optional
/**
 *  There is a new heading from the compass. Heading is filtered using some filtering factors.
 *
 *  @param heading Most recent heading
 */
- (void)manager:(IFLocationManager *)manager headingChanged:(float)heading;

@end

/**
 *  The `IFLocationManager` recives current user position and fetch nearby data (beacons, buildings). 
 *  This class helped also in presenting data on the map.
 */
@interface IFLocationManager : NSObject <CLLocationManagerDelegate>

/**
 *  Delegate responsible for passing all the events from the manager
 */
@property(nonatomic, weak) id<IFLocationManagerDelegate>delegate;

/**
 *  Each manager is a singleton, they are accessible by the sharedManager method
 *
 *  @return IFLocationManager object
 */
+ (IFLocationManager *)sharedManager;

/**
 *  MapKit allows to use maximum 21 level of zoom only. That's why we need to trick it a little bit with some translations.
 *
 *  @param latlng Nearby coordinate
 */
- (void) setTranslationCoordinate:(CLLocationCoordinate2D)latlng;

/**
 *  Every coordinate needs to be transformed using this method, to get the proper scaling factor within the application
 *
 *  @param coordinate Original coordinate
 *
 *  @return Transformed coordinate
 */
- (CLLocationCoordinate2D) translateCoordinate: (CLLocationCoordinate2D) coordinate;

/**
 *  When we need to get back the original coordinate
 *
 *  @param coordinate Transformed coordinate
 *
 *  @return Original coordinate
 */
- (CLLocationCoordinate2D) translateBack: (CLLocationCoordinate2D) coordinate;

/**
 *  Current zoom factor
 *
 *  @return zoom factor
 */
- (int) zoomFactor;

/**
 *  If we're good with 21 zoom level, we don't need to enable translation methods. You should enable this only when you want to launch zoom level more than 22
 *
 *  @param status Translation status
 */
- (void)setTranslationEnabled:(BOOL)status;

/**
 *  Verify the translation status
 *
 *  @return Translation status
 */
- (BOOL)isTranslationEnabled;

/**
 *  We need to monitor current user position in order to get nearby buildings and beacons. The position should be passed using updateCurrentLocation: method
 *
 *  @param location current user location
 */
- (void)updateCurrentLocation:(CLLocation *)location;

@end