// 362. Design Hit Counter
// Difficulty : Medium

// Design a hit counter which counts the number of hits received in the past 5 minutes.

// Each function accepts a timestamp parameter (in seconds granularity)
// and you may assume that calls are being made to the system in chronological order
// (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

// It is possible that several hits arrive roughly at the same time.

// Example:
// HitCounter counter = new HitCounter();

// hit at timestamp 1.
// counter.hit(1);

// hit at timestamp 2.
// counter.hit(2);

// hit at timestamp 3.
// counter.hit(3);

// get hits at timestamp 4, should return 3.
// counter.getHits(4);

// hit at timestamp 300.
// counter.hit(300);

// get hits at timestamp 300, should return 4.
// counter.getHits(300);

// get hits at timestamp 301, should return 3.
// counter.getHits(301);
// Follow up:
// What if the number of hits per second could be very large? Does your design scale?

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

// Time:  O(1), amortized
// Space: O(k), k is the count of seconds.

#import <Foundation/Foundation.h>

#pragma mark DeQueue

@interface DeQueue : NSObject

- (instancetype)init;
- (id)popFront;
- (id)popBack;
- (void)pushFront:(id)element;
- (void)pushBack:(id)element;
- (id)front;
-(id)back;
-(BOOL)isEmpty;
-(NSInteger)count;

@end

#pragma mark Solution

@interface HitCounter : NSObject
@end

@implementation HitCounter

const int _k = 300;
int _count;
DeQueue* _dequeue;

-(instancetype)initWithCount:(int)count {
  self = [super init];
  if (self) {
    _count = count;
    _dequeue = [[DeQueue alloc] init];
  }
  return self;
}

/** Record a hit.
 @param timestamp - The current timestamp (in seconds granularity). */
-(void)hitTimestamp:(int)timestamp {
  [self getHitsOnTimestamp:timestamp];
  if (![_dequeue isEmpty] && [[_dequeue back][0] intValue] == timestamp) {
    [_dequeue back][1] = @([[_dequeue back][1] intValue] + 1);
  } else {
    [_dequeue pushBack:@[@(timestamp), @1]];
  }
  ++_count;
}

/** Return the number of hits in the past 5 minutes.
 @param timestamp - The current timestamp (in seconds granularity). */
-(int)getHitsOnTimestamp:(int)timestamp {
  while (![_dequeue isEmpty] && [[_dequeue front][0] intValue] <= timestamp - _k) {
    _count -= [[_dequeue popFront][1] intValue];
  }
  return _count;
}

@end