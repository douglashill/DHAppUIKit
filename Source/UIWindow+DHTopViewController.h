// Douglas Hill, November 2013
// https://github.com/douglashill/DHAppUIKit

@import UIKit;

@interface UIWindow (DHTopViewController)

/**
 @brief Returns the top presented view controller on the window’s root view controller.
 @return The top presented view controller on the window’s root view controller.
 */
- (nullable UIViewController *)dh_topViewController;

@end
