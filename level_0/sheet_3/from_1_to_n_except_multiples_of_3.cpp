#include <iostream>
using namespace std;

int main() {
  /*
    We can find out if a number A is divisible by another
    number B if A % B = 0 (why does this work?)
  */

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    if (i % 3 != 0) {
      cout << i << ' ';
    }
  }

  return 0;
}
