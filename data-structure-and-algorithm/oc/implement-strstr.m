// 28. Implement strStr()
// Difficulty: Easy

// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Time:  O(n + k)
// Space: O(k)

#import <Foundation/Foundation.h>

NSArray* getPrefix(NSString* pattern) {
  NSMutableArray* prefix = [NSMutableArray arrayWithCapacity:[pattern length]];
  for (NSInteger i = 0; i < [pattern length]; i++) {
    prefix[i] = [NSNumber numberWithInteger:-1];
  }
  NSInteger j = -1;
  for (NSInteger i = 1; i < [pattern length]; ++i) {
    while (j > -1 && [pattern characterAtIndex:j + 1] != [pattern characterAtIndex:i]) {
      j = [prefix[j] intValue];
    }
    if ([pattern characterAtIndex:j + 1] == [pattern characterAtIndex:i]) {
      ++j;
    }
    prefix[i] = [NSNumber numberWithInteger:j];
  }
  return [prefix copy];
}

NSInteger KMP(NSString* text, NSString* pattern) {
  NSArray* prefix = getPrefix(pattern);
  NSInteger j = -1;
  for (NSInteger i = 0; i < [text length]; ++i) {
    while (j > -1 && [pattern characterAtIndex:j + 1] != [text characterAtIndex:i]) {
      j = [prefix[j] intValue];
    }
    if ([pattern characterAtIndex:j + 1] == [text characterAtIndex: i]) {
      ++j;
    }
    if (j == [pattern length] - 1) {
      return i - j;
    }
  }
  return -1;
}

NSInteger strStr(NSString* haystack, NSString* needle) {
  if ([needle length] == 0) {
    return 0;
  }
  return KMP(haystack, needle);
}

// Time:  O(n^2)
// Space: O(k)

#import <Foundation/Foundation.h>

NSInteger strStr(NSString *haystack, NSString *needle) {
  for (NSInteger i = 0; i <= [haystack length] - [needle length]; i++) {
    for (NSInteger j = 0; j < [needle length]; j++){
      
      if ([haystack characterAtIndex:i + j] != [needle characterAtIndex:j]) {
        break;
      }
      if (j == [needle length] - 1) {
        return i;
      }
    }
  }
  return -1;
}