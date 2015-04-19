// Douglas Hill, August 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

@interface DHFormatterTransformer : NSValueTransformer

- (nonnull instancetype)init NS_UNAVAILABLE;

/// Designated initialiser
- (nonnull instancetype)initWithFormatter:(nonnull NSFormatter *)formatter;

@property (nonatomic, nonnull, strong, readonly) NSFormatter *formatter;

@end
