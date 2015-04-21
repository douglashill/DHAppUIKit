// Douglas Hill, August 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

/**
 DHFormatterTransformer transforms between objects and strings using instance-specific NSFormatter objects.
 */
@interface DHFormatterTransformer : NSValueTransformer

/**
 Formatter transformer must be initialised with a formatter. The implementation of this method raises an exception.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 @brief Initialises a formatter transformer with a specified formatter.
 This is the designated initialiser.
 @param formatter The formatter, which must support both formatting and parsing.
 @return An initialised formatter transformer that uses @c formatter to transform between objects and strings.
 */
- (nonnull instancetype)initWithFormatter:(nonnull NSFormatter *)formatter;

/**
 The formatter used by the transformer that supports both formatting and parsing. (read-only)
 */
@property (nonatomic, nonnull, strong, readonly) NSFormatter *formatter;

@end
