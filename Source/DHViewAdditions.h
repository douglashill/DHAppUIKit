// Douglas Hill, April 2015
// https://github.com/douglashill/DHAppUIKit

@import Darwin.TargetConditionals;

#if TARGET_OS_IPHONE

@import UIKit;
#define DH_VIEW UIView
#define DH_EDGE_INSETS UIEdgeInsets

#else

@import AppKit;
#define DH_VIEW NSView
#define DH_EDGE_INSETS NSEdgeInsets

#endif

@interface DH_VIEW (DHConstraintConveniences)

/**
 Adds a layout constraint to the view for a given layout attribute to be equal to a given value. Typically used to set a fixed width or height.
 @param attribute The layout attribute to constrain.
 @param constant  The value to constrain the attribute to be equal to.
 */
- (void)dh_constrainAttribute:(NSLayoutAttribute)attribute toConstant:(CGFloat)constant;

/**
 Adds a layout constraint to the view for a given layout attribute, relationship and value. Typically used to set a fixed, minimum or maximum width or height.
 @param attribute The layout attribute to constrain.
 @param relation  The relationship between the view’s attribute and the constant.
 @param constant  The value the attribute will be related to.
 */
- (void)dh_constrainAttribute:(NSLayoutAttribute)attribute relatedBy:(NSLayoutRelation)relation toConstant:(CGFloat)constant;

/**
 Adds layout constraints to the view so its frame matches the bounds of its superview.
 */
- (void)dh_constrainToFillSuperview;

/**
 Adds layout constraints to the view so its frame matches the bounds of its superview after applying given insets.
 @param insets The insets to use when creating the layout constraints.
 */
- (void)dh_constrainToFillSuperviewWithInsets:(DH_EDGE_INSETS)insets;

@end

typedef BOOL(^DHSubviewsPredicte)(DH_VIEW *__nonnull view);

@interface DH_VIEW (DHSubviews)

/**
 Returns a set obtained by flattening and filtering the view tree, starting at, and including, the receiver.
 @param predicate The block that returns YES if its view argument should be included in the returned set, and NO if not.
 @return A set containing any of the receiver and its subviews that return YES when passed to predicate, or the receiver and all its subviews if predicate is nil.
 */
- (nonnull NSSet *)dh_recursiveSubviewsPassingTest:(nullable DHSubviewsPredicte)predicate;

@end
