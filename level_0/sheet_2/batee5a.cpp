#include <iostream>
using namespace std;

int main() {
  /*
    Any even number except two could be divided into
    two even parts.
    Proof by exhaustion:
    4 = 2 + 2
    6 = 2 + 4
    8 = 2 + 6
    ...
    n = 2 + (n - 2)
    This works for all even numbers greater than 2
  */

  int w;
  cin >> w;

  if (w > 2 && w % 2 == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}