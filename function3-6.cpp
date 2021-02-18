# include <iostream>
# include <cstdlib>
using namespace std;

enum GameStatus {WIN, LOSE, PLAYING};
int rollDice();

int main() {
  int sum, myPoint;
  GameStatus status;
  unsigned seed;
  cout << "Please enter an unsigned integer: ";
  cin >> seed;
  srand(seed);
  sum = rollDice();
  switch (sum) {
    case 7:
    case 11:
      status = WIN;
      break;
    case 2:
    case 3:
    case 12:
      status = LOSE;
      break;
    default:
      status = PLAYING;
      myPoint = sum;
      cout << "point is " << myPoint << endl;
      break;
  }
  while (status == PLAYING) {
    sum = rollDice();
    if (sum == myPoint)
      status = WIN;
    else if (sum == 7)
      status = LOSE;
  }

  if (status == WIN)
    cout << "player wins" << endl;
  else
    cout << "player loses" << endl;
  return 0;
}

int rollDice() {
  int die1 = 1 + rand() % 6;
  int die2 = 1 + rand() % 6;
  int sum = die1 + die2;
  cout << "player rolled " << die1 << " + " << die2 << " = " << sum << endl;
  return sum;
}