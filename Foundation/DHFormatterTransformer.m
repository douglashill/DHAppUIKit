// Douglas Hill, October 2014
// https://github.com/douglashill/DHUtilities

#import "DHFormatterTransformer.h"

#import "DHExceptionCreation.h"

@implementation DHFormatterTransformer

- (instancetype)init
{
	@throw DH_EXCEPTION(NSInvalidArgumentException, @"%@ must be initialised using initWithFormatter:.", [self class]);
}

- (nonnull instancetype)initWithFormatter:(nonnull NSFormatter *)formatter
{
	self = [super init];
	
	_formatter = formatter;
	
	return self;
}

+ (Class)transformedValueClass
{
	return [NSString class];
}

+ (BOOL)allowsReverseTransformation
{
	return YES;
}

- (NSString *)transformedValue:(id)value
{
	return [[self formatter] stringForObjectValue:value];
}

- (id)reverseTransformedValue:(NSString *)string
{
	id value;
	NSString *errorDescription;
	if (![[self formatter] getObjectValue:&value forString:string errorDescription:&errorDescription]) {
		NSLog(@"%@ could not reverse transform %@ using %@: %@", [self class], string, [self formatter], errorDescription);
		return nil;
	}
	
	return value;
}

@end
