//
//  UIImage+Resize.swift
//  MyLocations
//
//  Created by ZhangZehua on 12/10/15.
//  Copyright © 2015 ZhangZehua. All rights reserved.
//

import UIKit

extension UIImage {
    func resizedImageWithBounds(bounds: CGSize) -> UIImage {
        let horizontalRatio = bounds.width / size.width
        let verticalRatio = bounds.height / size.height
        let ratio = min(horizontalRatio, verticalRatio)
        let newSize = CGSize(
            width: size.width * ratio,
            height: size.height * ratio)
        
        UIGraphicsBeginImageContextWithOptions(newSize, true, 0)
        drawInRect(CGRect(origin: CGPoint.zero, size: newSize))
        let newImage = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        
        return newImage
    }
}
