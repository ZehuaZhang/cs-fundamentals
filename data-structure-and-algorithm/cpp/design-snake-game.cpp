// 353. Design Snake Game
// Difficulty : Medium 

// Design a Snake game that is played on a device with screen size = width x height.
// Play the game online if you are not familiar with the game.

// The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

// You are given a list of food's positions in row-column order. When a snake eats the food,
// its length and the game's score both increase by 1.

// Each food appears one by one on the screen. For example, the second food will not appear 
// until the first food was eaten by the snake.

// When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

// Example:
// Given width = 3, height = 2, and food = [[1,2],[0,1]].

// Snake snake = new Snake(width, height, food);

// Initially the snake appears at position (0,0) and the food at (1,2).

// |S| | |
// | | |F|

// snake.move("R"); -> Returns 0

// | |S| |
// | | |F|

// snake.move("D"); -> Returns 0

// | | | |
// | |S|F|

// snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

// | |F| |
// | |S|S|

// snake.move("U"); -> Returns 1

// | |F|S|
// | | |S|

// snake.move("L"); -> Returns 2 (Snake eats the second food)

// | |S|S|
// | | |S|

// snake.move("U"); -> Returns -1 (Game over because snake collides with border)

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */

// Time:  O(s) per move, s is the current length of the snake.
// Space: O(s)

class SnakeGame {
public:
  /** Initialize your data structure here.
      @param width - screen width
      @param height - screen height 
      @param food - A list of food positions
      E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
  SnakeGame(int width, int height, vector<pair<int, int>> food) :
    _width{width}, _height{height}, _score{0},
    _food{food.begin(), food.end()}, _snake{{0, 0}}  {
  }

  /** Moves the snake.
    @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
    @return The game's score after the move. Return -1 if game over. 
    Game over when snake crosses the screen boundary or bites its body. */
  int move(string direction) {
    const auto x = _snake.front().first + _direction[direction].first;
    const auto y = _snake.front().second + _direction[direction].second;
    const auto tail = _snake.back();

    _snake.pop_back();
    if (!valid(x, y)) {
      return -1;
    } else if (!_food.empty() && _food.front().first == x && _food.front().second == y) {
      ++_score;
      _food.pop_front();
      _snake.push_back(tail);
    }
    _snake.push_front({x, y});
    return _score;
  }

private:
  bool valid(int x, int y) {
    if (x < 0 || x >= _height || y < 0 || y >= _width) {
      return false;
    }
    for (auto part : _snake) {
      if (x == part.first && y == part.second) {
        return false;
      }
    }
    return true;
  }
  int _width, _height, _score;
  deque<pair<int, int>> _food, _snake;
  unordered_map<string, pair<int, int>> _direction = {{"U", {-1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}, {"D", {1, 0}}};
};