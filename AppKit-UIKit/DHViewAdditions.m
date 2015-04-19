// Douglas Hill, April 2015
// https://github.com/douglashill/DHUtilities

#import "DHViewAdditions.h"

static NSDictionary *DHDictionaryFromEdgeInsets(DH_EDGE_INSETS edgeInsets)
{
	return @{
			 @"top"    : @(edgeInsets.top),
			 @"left"   : @(edgeInsets.left),
			 @"bottom" : @(edgeInsets.bottom),
			 @"right"  : @(edgeInsets.right),
			 };
}

@implementation DH_VIEW (DHConstraintConveniences)

- (void)dh_constrainAttribute:(NSLayoutAttribute)attribute toConstant:(CGFloat)constant
{
	[self dh_constrainAttribute:attribute relatedBy:NSLayoutRelationEqual toConstant:constant];
}

- (void)dh_constrainAttribute:(NSLayoutAttribute)attribute relatedBy:(NSLayoutRelation)relation toConstant:(CGFloat)constant
{
	[self addConstraint:[NSLayoutConstraint constraintWithItem:self attribute:attribute
													 relatedBy:relation
														toItem:nil attribute:NSLayoutAttributeNotAnAttribute
													multiplier:0 constant:constant]];
}

- (void)dh_constrainToFillSuperview
{
	[self dh_constrainToFillSuperviewWithInsets:(DH_EDGE_INSETS){}];
}

- (void)dh_constrainToFillSuperviewWithInsets:(DH_EDGE_INSETS)insets
{
	NSDictionary *const metrics = DHDictionaryFromEdgeInsets(insets);
	NSDictionary *const views = @{@"self" : self};
	[[self superview] addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-left-[self]-right-|" options:0 metrics:metrics views:views]];
	[[self superview] addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-top-[self]-bottom-|" options:0 metrics:metrics views:views]];
}

@end

@implementation DH_VIEW (DHSubviews)

- (NSSet *)dh_recursiveSubviewsPassingTest:(DHSubviewsPredicte)predicate
{
	NSMutableSet *viewsPassingTest = [NSMutableSet set];
	
	[self dh_addSelfAndRecursiveSubviewsToSet:viewsPassingTest ifPassingTest:predicate];
	
	return viewsPassingTest;
}

- (void)dh_addSelfAndRecursiveSubviewsToSet:(NSMutableSet *)set ifPassingTest:(DHSubviewsPredicte)predicate
{
	if (predicate == nil || predicate(self)) [set addObject:self];
	
	for (DH_VIEW *subview in [self subviews]) {
		[subview dh_addSelfAndRecursiveSubviewsToSet:set ifPassingTest:predicate];
	}
}

@end
