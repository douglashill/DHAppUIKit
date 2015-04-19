// Douglas Hill, April 2015
// https://github.com/douglashill/DHUtilities

@import Foundation;

#define DH_EXCEPTION(name, format, ...) [[NSException alloc] initWithName:name reason:[NSString stringWithFormat:format, __VA_ARGS__] userInfo:nil]
