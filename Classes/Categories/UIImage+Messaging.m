//
//  UIImage+Messaging.h
//  MessagingKit
//
//  GitHub
//  https://github.com/DevonBoyer/MessagingKit
//
//  Created by Devon Boyer on 2014-09-18.
//  Copyright (c) 2014 Devon Boyer. All rights reserved.
//

#import "UIImage+Messaging.h"

#import <MediaPlayer/MediaPlayer.h>
#import <AVFoundation/AVFoundation.h>

@implementation UIImage (Messaging)

+ (UIImage *)imageForFrameAtTime:(NSTimeInterval)time movieURL:(NSURL *)movieURL {
    
    __block UIImage *frameImage = nil;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        AVURLAsset *asset1 = [[AVURLAsset alloc] initWithURL:movieURL options:nil];
        AVAssetImageGenerator *generate1 = [[AVAssetImageGenerator alloc] initWithAsset:asset1];
        generate1.appliesPreferredTrackTransform = YES;
        NSError *error = nil;
        CGImageRef frameRef = [generate1 copyCGImageAtTime:CMTimeMake(time, 1) actualTime:NULL error:&error];
        frameImage = [[UIImage alloc] initWithCGImage:frameRef];
    });
    
    return frameImage;
}

- (UIImage *)imageWithColor:(UIColor *)color
{
    CGRect imageRect = CGRectMake(0.0f, 0.0f, self.size.width, self.size.height);
    
    UIGraphicsBeginImageContextWithOptions(imageRect.size, NO, self.scale);
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextScaleCTM(context, 1.0f, -1.0f);
    CGContextTranslateCTM(context, 0.0f, -(imageRect.size.height));
    
    CGContextClipToMask(context, imageRect, self.CGImage);
    CGContextSetFillColorWithColor(context, color.CGColor);
    CGContextFillRect(context, imageRect);
    
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return newImage;
}

@end