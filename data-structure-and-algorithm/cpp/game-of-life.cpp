// 289. Game of Life
// Difficulty: Medium

// According to the Wikipedia article: "The Game of Life, also known simply as Life, 
// is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
// Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules
// (taken from the above Wikipedia article):

// 1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// 2. Any live cell with two or three live neighbors lives on to the next generation.
// 3. Any live cell with more than three live neighbors dies, as if by over-population..
// 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// Write a function to compute the next state (after one update) of the board given its current state.

// Follow up: 
// 1. Could you solve it in-place? Remember that the board needs to be updated at the same time: 
// You cannot update some cells first and then use their updated values to update other cells.
// 2. In this question, we represent the board using a 2D array. In principle, the board is infinite, 
// which would cause problems when the active area encroaches the border of the array. How would you address these problems?

// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    const int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int count = 0;
        // Count live cells in 3x3 block.
        for (int I = max(i - 1, 0); I < min(i + 2, m); ++I) {
          for (int J = max(j - 1, 0); J < min(j + 2, n); ++J) {
            count += board[I][J] & 1;
          }
        }
        // if (count == 4 && board[i][j]) means:
        //     Any live cell with three live neighbors lives.
        // if (count == 3) means:
        //     Any live cell with two live neighbors.
        //     Any dead cell with exactly three live neighbors lives.
        // to summarize, consider #2, & #3 scenarios where next state of board element lives
        if ((count == 4 && (board[i][j] & 1)) || count == 3) {
          board[i][j] |= 2;  // Mark as live. 
        }
      }
    }
    // Update to the next state
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        board[i][j] >>= 1;  
      }
    }
  }
};
