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

  // sort(beginning of array, end of array + 1)
  // sorts in ascending by default
  sort(a, a + n);

  while (q--) {
    int x;
    cin >> x;

    bool found = false;  // assume x is not found

    // standard binary search
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[mid] == x) {
        found = true;
        break;
      } else if (a[mid] < x) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    // similar to an if(found) but easier to type
    cout << (found ? "found" : "not found") << '\n';
  }

  return 0;
}