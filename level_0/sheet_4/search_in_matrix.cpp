#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int a[n][m];  // 2D array declaration

  // 2D array input
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  int x;
  cin >> x;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == x) {
        cout << "will not take number";
        return 0;
      }
    }
  }

  cout << "will take number";

  return 0;
}