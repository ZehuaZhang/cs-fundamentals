// 79. Word Search
// Difficulty: Medium

// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell,
//  where "adjacent" cells are those horizontally or vertically neighboring.
//  The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

// Time Complexity: O(m * n * 4 ^ p), where m is board width, n is board height, p is word length
// Space Complexity: O(m * n + p)

#import <Foundation/Foundation.h>

BOOL existHelper(NSArray* board, NSString* word, int index, NSInteger i, NSInteger j, BOOL *visited) {
  const NSInteger n = [board[0] count];
  
  if (index == [word length]) {
    return YES;
  }
  if (i < 0 || j < 0 || i >= [board count] || j >= [board[0] count]
      || visited[i * n + j]
      || [board[i][j] charValue] != [word characterAtIndex:index]) {
    return NO;
  }
  
  visited[i * n + j] = YES;
  bool isValid = existHelper(board, word, index + 1,  i + 1, j, visited)
  || existHelper(board, word, index + 1,  i, j + 1, visited)
  || existHelper(board, word, index + 1,  i - 1, j, visited)
  || existHelper(board, word, index + 1,  i, j - 1, visited);
  visited[i * n + j] = NO;
  
  return isValid;
}

BOOL exist(NSArray* board, NSString* word) {
  const NSInteger m = [board count];
  const NSInteger n = [board[0] count];
  BOOL visited[m * n];
  memset(visited, 0, sizeof(BOOL) * m * n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (existHelper(board, word, 0, i, j, visited)) {
        return YES;
      }
    }
  }
  return NO;
}