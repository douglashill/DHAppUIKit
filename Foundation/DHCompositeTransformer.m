// Douglas Hill, October 2014
// https://github.com/douglashill/DHUtilities

#import "DHCompositeTransformer.h"

#import "DHExceptionCreation.h"
#import "NSArray+DHFold.h"

@implementation DHCompositeTransformer

+ (nonnull NSArray *)transformerClasses
{
	@throw DH_EXCEPTION(NSInternalInconsistencyException, @"Subclasses must override %s.", __PRETTY_FUNCTION__);
}

- (instancetype)init
{
	return [self initWithTransformers:nil];
}

- (nonnull instancetype)initWithTransformers:(nullable NSArray *)transformers
{
	self = [super init];
	
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
