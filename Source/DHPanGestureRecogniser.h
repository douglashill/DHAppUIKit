// Douglas Hill, July 2015
// https://github.com/douglashill/DHAppUIKit

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface DHPanGestureRecogniser : UIPanGestureRecognizer

/// Returns the predicted current location of the pan gesture.
/// If no prediction is available, this method falls back on `locationInView:`.
/// @note I’m not confident this will work correctly in all situations.
- (CGPoint)predictedLocationInView:(nullable UIView *)view;

@end

NS_ASSUME_NONNULL_END
