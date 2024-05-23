#include <iostream>
using namespace std;

int main() {
  // (Hard version: Could you solve it without for loops?)

  int n;
  cin >> n;

  long long sum_even = 0, sum_odd = 0;

  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      sum_even += i;
    } else {
      sum_odd += i;
    }
  }

  cout << sum_even << ' ' << sum_odd;

  return 0;
}