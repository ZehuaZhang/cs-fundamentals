//
//  DetailViewController.swift
//  StoreSearch
//
//  Created by ZhangZehua on 1/7/16.
//  Copyright © 2016 ZhangZehua. All rights reserved.
//

import UIKit
import MessageUI

class DetailViewController: UIViewController {

    var searchResult: SearchResult! {
        didSet {
            if isViewLoaded() {
                updateUI()
            }
        }
    }
    var downloadTask: NSURLSessionDownloadTask?
    
    var isPopUp = false
    
    enum AnimationStyle {
        case Slide
        case Fade
    }
    
    var dismissAnimationStyle = AnimationStyle.Fade
    
    @IBOutlet weak var popupView: UIView!
    @IBOutlet weak var artworkImageView: UIImageView!
    @IBOutlet weak var nameLabel: UILabel!
    @IBOutlet weak var artistNameLabel: UILabel!
    @IBOutlet weak var kindLabel: UILabel!
    @IBOutlet weak var genreLabel: UILabel!
    @IBOutlet weak var priceButton: UIButton!
    
    @IBAction func close() {
        dismissAnimationStyle = .Slide
        dismissViewControllerAnimated(true, completion: nil)
    }
    
    @IBAction func openInStore() {
        if let url = NSURL(string: searchResult.storeURL) {
            UIApplication.sharedApplication().openURL(url)
        }
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        modalPresentationStyle = .Custom
        transitioningDelegate = self
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        view.tintColor = UIColor(red: 20 / 255, green: 160 / 255, blue: 160 / 255, alpha: 1)
        popupView.layer.cornerRadius = 10
        
        if searchResult != nil {
            updateUI()
        }
        
        if isPopUp {
            let gestureRecognizer = UITapGestureRecognizer(target: self, action: Selector("close"))
            gestureRecognizer.cancelsTouchesInView = false
            gestureRecognizer.delegate = self
            view.addGestureRecognizer(gestureRecognizer)
            
            view.backgroundColor = UIColor.clearColor()
        } else {
            view.backgroundColor = UIColor(patternImage: UIImage(named: "LandscapeBackground")!)
            
            if let displayName = NSBundle.mainBundle().localizedInfoDictionary?["CFBundleDisplayName"]as? NSString {
                title = displayName as String
            }
            
            popupView.hidden = true
        }
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "ShowMenu" {
            let controller = segue.destinationViewController as! MenuViewController
            controller.delegate = self
        }
    }
    
    deinit {
        print("deinit \(self)")
        downloadTask?.cancel()
    }
    
    func updateUI() {
        nameLabel.text = searchResult.name
        
        if searchResult.artistName.isEmpty {
            artistNameLabel.text = NSLocalizedString("Unknown", comment: "Artist Name is Unknown")
        } else {
            artistNameLabel.text = searchResult.artistName
        }
        
        kindLabel.text = searchResult.kindForDisplay()
        genreLabel.text = searchResult.genre
        
        let formatter = NSNumberFormatter()
        formatter.numberStyle = .CurrencyStyle
        formatter.currencyCode = searchResult.currency
        
        var priceText: String
        if searchResult.price == 0 {
            priceText = NSLocalizedString("Free", comment: "price of current searched item is free")
        } else if let text = formatter.stringFromNumber(searchResult.price) {
            priceText = text
        } else {
            priceText = ""
        }
        
        priceButton.setTitle(priceText, forState: .Normal)
        
        if let url = NSURL(string: searchResult.artworkURL100) {
            downloadTask = artworkImageView.loadImageWithURL(url)
        }
        popupView.hidden = false
    }
    
}

extension DetailViewController: UIViewControllerTransitioningDelegate {
    func presentationControllerForPresentedViewController(presented: UIViewController, presentingViewController presenting: UIViewController, sourceViewController source: UIViewController) -> UIPresentationController? {
        return DimmingPresentationController(presentedViewController: presented, presentingViewController: presenting)
    }
    
    func animationControllerForPresentedController(presented: UIViewController, presentingController presenting: UIViewController, sourceController source: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        return BounceAnimationController()
    }
    
    func animationControllerForDismissedController(dismissed: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        switch dismissAnimationStyle {
        case .Slide:
            return SlideOutAnimationController()
        case .Fade:
            return FadeOutAnimationController()
        }
    }
}

extension DetailViewController: UIGestureRecognizerDelegate {
    func gestureRecognizer(gestureRecognizer: UIGestureRecognizer, shouldReceiveTouch touch: UITouch) -> Bool {
        return (touch.view === view)
    }
}

extension DetailViewController: MenuViewControllerDelegate {
    func menuViewControllerSendSupportEmail(_: MenuViewController) {
        dismissViewControllerAnimated(true) {
            if MFMailComposeViewController.canSendMail() {
                let controller = MFMailComposeViewController()
                controller.setSubject(NSLocalizedString("Support Request", comment: "Email subject"))
                controller.setToRecipients(["your@email-address-here.com"])
                
                controller.mailComposeDelegate = self
                controller.modalPresentationStyle = .FormSheet
                
                self.presentViewController(controller, animated: true, completion: nil)
            }
        }
    }
}

extension DetailViewController: MFMailComposeViewControllerDelegate {
    func mailComposeController(controller: MFMailComposeViewController, didFinishWithResult result: MFMailComposeResult, error: NSError?) {
        dismissViewControllerAnimated(true, completion: nil)
    }
}