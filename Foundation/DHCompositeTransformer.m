// Douglas Hill, October 2014
// https://github.com/douglashill/Objective-C-bits-and-bobs

#import "DHCompositeTransformer.h"

#import "NSArray+DHFold.h"

@implementation DHCompositeTransformer

+ (NSArray *)transformerClasses
{
	[NSException raise:NSInternalInconsistencyException format:@"Subclasses must override %s.", __PRETTY_FUNCTION__];
	return nil;
}

- (instancetype)init
{
	return [self initWithTransformers:nil];
}

- (instancetype)initWithTransformers:(NSArray *)transformers
{
	self = [super init];
	if (self == nil) return nil;
	
	_transformers = transformers ? [transformers copy] : [[[self class] transformerClasses] valueForKey:NSStringFromSelector(@selector(new))];
	
	return self;
}

+ (Class)transformedValueClass
{
	return [[[self transformerClasses] lastObject] transformedValueClass];
}

+ (BOOL)allowsReverseTransformation
{
	// Two possible implementations
	
//	return [[[self transformerClasses] valueForKey:NSStringFromSelector(_cmd)] containsObject:@NO] == NO;
	
	return [[[self transformerClasses] dh_foldWithInitialValue:@YES options:0 usingBlock:^id(Class transformerClass, id value) {
		return @([value boolValue] && [transformerClass allowsReverseTransformation]);
	}] boolValue];
}

- (id)transformedValue:(id)initialValue
{
	return [[self transformers] dh_foldWithInitialValue:initialValue options:0 usingBlock:^id (NSValueTransformer *transformer, id value) {
		return [transformer transformedValue:value];
	}];
}

- (id)reverseTransformedValue:(id)initialValue
{
	return [[self transformers] dh_foldWithInitialValue:initialValue options:NSEnumerationReverse usingBlock:^id (NSValueTransformer *transformer, id value) {
		return [transformer reverseTransformedValue:value];
	}];
}

@end
