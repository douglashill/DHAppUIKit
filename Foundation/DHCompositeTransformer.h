// Douglas Hill, October 2014
// https://github.com/douglashill/Objective-C-bits-and-bobs

@import Foundation;

@interface DHCompositeTransformer : NSValueTransformer

/// Subclasses must override.
+ (NSArray *)transformerClasses;

/// Designated initialiser. `transformers` may be `nil` (or call `init`) if custom creation of the transformers is not needed.
- (instancetype)initWithTransformers:(NSArray *)transformers;

@property (nonatomic, copy, readonly) NSArray *transformers;

@end
