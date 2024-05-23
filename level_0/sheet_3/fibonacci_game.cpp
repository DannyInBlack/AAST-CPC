#include <iostream>
using namespace std;

int main() {
  /*
    NOTE: This problem was not meant to be solved recursively
    This requires a concept called DP - Dynamic Programming (why?)
    (could you solve it using recusion?)
    Instead, use a for loop and begin from i = 2
  */

  int n;
  cin >> n;

  int a = 1, b = 1, c = 1;

  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  cout << c;

  return 0;
}