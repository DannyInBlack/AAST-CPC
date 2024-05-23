#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Check each number and number in opposite position
  // a[i] must be equal to a[n - i - 1]
  // Example: a[0] must be equal to (a[5 - 0 - 1]) a[4]
  // We only need to check until (n / 2 - 1) (why?)

  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n / 2; i++) {
    if (a[i] != a[n - i - 1]) {
      cout << "NO";
      return 0;  // Force exit the program
    }
  }

  cout << "YES";

  return 0;
}