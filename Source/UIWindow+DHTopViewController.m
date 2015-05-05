// Douglas Hill, November 2013
// https://github.com/douglashill/DHAppUIKit

#import "UIWindow+DHTopViewController.h"

@implementation UIWindow (DHTopViewController)

- (nullable UIViewController *)dh_topViewController
{
	UIViewController *viewController = [self rootViewController];
	
	while ([viewController presentedViewController]) {
		viewController = [viewController presentedViewController];
	}
	
	return viewController;
}

@end
