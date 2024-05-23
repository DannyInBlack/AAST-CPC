#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int a[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  ll sum_diag_1 = 0, sum_diag_2 = 0;

  for (int i = 0; i < n; i++) {
    sum_diag_1 += a[i][i];
  }

  for (int i = 0; i < n; i++) {
    sum_diag_2 += a[i][n - i - 1];
  }

  // abs returns the absolute (negative becomes positive)
  cout << abs(sum_diag_1 - sum_diag_2);

  return 0;
}