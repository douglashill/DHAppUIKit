// Douglas Hill, April 2015
// https://github.com/douglashill/DHUtilities

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

- (void)dh_constrainAttribute:(NSLayoutAttribute)attribute toConstant:(CGFloat)constant;

/// Adds a constraint to the receiver with the specified properties. Typically used to set a fixed/minimum/maximum width/height.
- (void)dh_constrainAttribute:(NSLayoutAttribute)attribute relatedBy:(NSLayoutRelation)relation toConstant:(CGFloat)constant;

- (void)dh_constrainToFillSuperview;
- (void)dh_constrainToFillSuperviewWithInsets:(DH_EDGE_INSETS)insets;

@end

typedef BOOL(^DHSubviewsPredicte)(DH_VIEW *view);

@interface DH_VIEW (DHSubviews)

/// Flattens and filters the view tree, starting at, and including, the receiver. Returns views that return YES when passed to predicate, or everything in the view tree if predicate is nil.
- (NSSet *)dh_recursiveSubviewsPassingTest:(DHSubviewsPredicte)predicate;

@end
