// Douglas Hill, October 2014
// https://github.com/douglashill/DHUtilities

@import Foundation;

@interface DHCompositeTransformer : NSValueTransformer

/// Subclasses must override.
+ (nonnull NSArray *)transformerClasses;

/// Designated initialiser. `transformers` may be `nil` (or call `init`) if custom creation of the transformers is not needed.
- (nonnull instancetype)initWithTransformers:(nullable NSArray *)transformers;

@property (nonatomic, nonnull, copy, readonly) NSArray *transformers;

@end
