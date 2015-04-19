// Douglas Hill, November 2013
// https://github.com/douglashill/DHUtilities

@import UIKit;

@interface UIWindow (DHTopViewController)

/// Returns the top presented view controller on the receiver’s root view controller’s.
- (nullable UIViewController *)dh_topViewController;

@end
