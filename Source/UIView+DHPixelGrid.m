// Douglas Hill, September 2012
// https://github.com/douglashill/DHAppUIKit

#import "UIView+DHPixelGrid.h"

@implementation UIView (DHPixelGrid)

- (void)dh_alignToPixelGrid
{
	UIScreen *const screen = [[self window] screen] ?: [UIScreen mainScreen];
	CGFloat const scale = [screen scale];
	CGRect frame = [self frame];
	frame.origin.x = round(frame.origin.x * scale) / scale;
	frame.origin.y = round(frame.origin.y * scale) / scale;
	[self setFrame:frame];
}

@end
