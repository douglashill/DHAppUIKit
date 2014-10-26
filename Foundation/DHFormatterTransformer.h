// Douglas Hill, August 2014
// https://github.com/douglashill/Objective-C-bits-and-bobs

@import Foundation;

@interface DHFormatterTransformer : NSValueTransformer

/// Designated initialiser
- (instancetype)initWithFormatter:(NSFormatter *)formatter;

@property (nonatomic, strong, readonly) NSFormatter *formatter;

@end
