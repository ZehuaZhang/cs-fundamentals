//
//  UIImage+Resize.m
//  MyLocations
//
//  Created by ZhangZehua on 2/22/17.
//  Copyright © 2017 ZhangZehua. All rights reserved.
//

#import "UIImage+Resize.h"

@implementation UIImage (Resize)

- (UIImage *)resizedImageWithBounds:(CGSize)bounds {
  CGFloat horizontalRatio = bounds.width / self.size.width;
  CGFloat verticalRatio = bounds.height / self.size.height;
  CGFloat ratio = MIN(horizontalRatio, verticalRatio);
  CGSize newSize = CGSizeMake(self.size.width * ratio, self.size.height * ratio);
  
  UIGraphicsBeginImageContextWithOptions(newSize, YES, 0);
  [self drawInRect:CGRectMake(0, 0, newSize.width, newSize.height)];
  UIImage* newImage = UIGraphicsGetImageFromCurrentImageContext();;
  UIGraphicsEndImageContext();
  return newImage;
}

@end
