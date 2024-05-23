#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // We don't even need an array for this problem

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x <= 10) {
      cout << "A[" << i << "] = " << x << '\n';
    }
  }

  return 0;
}