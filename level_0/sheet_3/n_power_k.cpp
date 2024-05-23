#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  long long result = 1;

  for (int i = 0; i < k; i++) {
    result *= n;
  }

  cout << result;

  return 0;
}