#include "cameraissue.h"
#ifdef __APPLE__
#ifdef __OBJC__

#import "mac_camera.h"
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

bool CameraIssue::dealWithCamera()
{
    AVAuthorizationStatus st = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
    if (st == AVAuthorizationStatusAuthorized) {
        return true;
    }

    dispatch_group_t group = dispatch_group_create();

    __block bool accessGranted = false;

    if (st != AVAuthorizationStatusAuthorized) {
        dispatch_group_enter(group);
        [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {

            accessGranted = granted;
            NSLog(@"Granted!");
            dispatch_group_leave(group);
        }];
    }

    dispatch_group_wait(group, dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5.0 * NSEC_PER_SEC)));

    return accessGranted;
}
#endif
#endif
