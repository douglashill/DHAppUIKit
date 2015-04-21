// Douglas Hill, September 2012
// https://github.com/douglashill/DHUtilities

@import UIKit;

@interface UIView (DHPixelGrid)

/**
 @brief Changes the view’s frame so its origin is rounded to the nearest pixel boundary.
 This prevents the view being blurry due to interpolation. This method assumes all the superviews of the receiving view are also aligned to pixel boundaries.
 */
- (void)dh_alignToPixelGrid;

@end
