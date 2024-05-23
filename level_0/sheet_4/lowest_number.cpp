#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // read problem carefully! (especially the note part)
  // maintain a minimum variable, and one for its index

  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mn = a[0];
  int index = 0;

  for (int i = 1; i < n; i++) {
    if (a[i] < mn) {
      mn = a[i];
      index = i;
    }
  }

  // index + 1 since the problem is 1-based indexing
  cout << mn << ' ' << index + 1;

  return 0;
}