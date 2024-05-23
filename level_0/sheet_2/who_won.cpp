#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a > b) {
    cout << "BIGO";
  } else if (a == b) {
    cout << "DRAW";
  } else {
    cout << "BLOBO2";
  }

  return 0;
}