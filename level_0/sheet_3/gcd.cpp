#include <iostream>
// vv library that has gcd
#include <numeric>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  // method one: bruteforce

  int result = 1;

  for (int i = 2; i <= min(a, b); i++) {
    if (a % i == 0 && b % i == 0) {
      result = i;
    }
  }

  cout << result;

  /*
    Another method: using the built-in function.
    There are many functions in the c++ standard library
    that can be useful in CP. This is an example: gcd().
    It can be found in the numeric header
    (#include <numeric>)
    (Of course it is also in the <bits/stdc++.h> header)
  */

  // cout << gcd(a, b);

  return 0;
}