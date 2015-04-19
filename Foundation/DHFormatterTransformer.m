// Douglas Hill, October 2014
// https://github.com/douglashill/DHUtilities

#import "DHFormatterTransformer.h"

@implementation DHFormatterTransformer

- (id)init
{
	return [self initWithFormatter:nil];
}

- (instancetype)initWithFormatter:(NSFormatter *)formatter
{
	self = [super init];
	if (self == nil) return nil;
	
	if (formatter == nil) {
		[NSException raise:NSInvalidArgumentException format:@"%@ must not be initialised without a formatter.", [self class]];
	}
	
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
