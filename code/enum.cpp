# include <iostream>

using namespace std;

enum GameResult {WIN, LOSE, TIE, CANCEL};

int main() {
  // 两种定义枚举变量的方法
  GameResult result;
  enum GameResult omit = CANCEL;
  for (int count = WIN; count <= CANCEL; count ++) {
    result = GameResult(count);
    if (result == omit)
      cout << "The Game was cancelled" << endl;
    else {
      cout << "The game was played";
      if (result == WIN) cout << "and we won!";
      if (result == LOSE) cout << "and we lost";
      cout << endl;
    }
  }
  return 0;
}