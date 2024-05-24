#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a, a + n);

  while (q--) {
    string s;
    int x;
    cin >> s >> x;

    if (s == "lower_bound") {
      // lower and upper bound will return a + n if not found
      // to check if not found: (a + n - a) == n
      auto p = lower_bound(a, a + n, x);
      cout << (p - a == n? -1 : *p);
    } else if (s == "upper_bound") {
      auto p = upper_bound(a, a + n, x);
      cout << (p - a == n? -1 : *p);
    } else if (s == "binary_search") {
      // binary_search return boolean value
      cout << (binary_search(a, a + n, x)? "found" : "not found");
    }
    cout << '\n';
  }
  return 0;
}