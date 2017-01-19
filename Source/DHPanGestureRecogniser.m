// Douglas Hill, July 2015
// https://github.com/douglashill/DHAppUIKit

#import "DHPanGestureRecogniser.h"

@import UIKit.UIGestureRecognizerSubclass;

@interface DHPanGestureRecogniser ()

@property (nonatomic, strong, nullable) NSSet<UITouch *> *currentTouches;
@property (nonatomic, strong, nullable) UIEvent *currentEvent;

@end

@implementation DHPanGestureRecogniser

- (BOOL)canPredictTouches
{
	return [self state] == UIGestureRecognizerStateChanged && [self currentEvent] && [[self currentTouches] count] == 1 && [UIEvent instancesRespondToSelector:@selector(predictedTouchesForTouch:)];
}

- (CGPoint)predictedLocationInView:(nullable UIView *)view
{
	if ([self canPredictTouches] == NO) {
		return [self locationInView:view];
	}
	
	NSArray<UITouch *> *const predictedTouches = [[self currentEvent] predictedTouchesForTouch:[[self currentTouches] anyObject]];
	
	return [predictedTouches count] ? [[predictedTouches lastObject] locationInView:view] : [self locationInView:view];
}

#pragma mark - UIGestureRecognizer (UIGestureRecognizerProtected)

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
	[self setCurrentTouches:touches];
	[self setCurrentEvent:event];
	
	[super touchesMoved:touches withEvent:event];
}

@end
