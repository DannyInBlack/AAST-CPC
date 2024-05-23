#include <iostream>
using namespace std;

int main() {
  /*
    You could always fit floor((n * m) / 2) dominos
    Proof:
    Imagine a row of n squares.
    If n is even, then we can fit n / 2 dominos
    If n is odd, then we can fit floor(n / 2) dominos

    But if there is two rows of n squares, and n is odd, then
    we can still fit n dominos

    Therfore, there can only be at most one unfilled square
    (hence, the floor)
  */

  int m, n;
  cin >> m >> n;

  cout << (m * n) / 2;

  return 0;
}