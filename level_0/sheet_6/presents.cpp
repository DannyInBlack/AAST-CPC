#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  /*
    When giving a gift, store the person who gave it in an array
  */

  int n;
  cin >> n;

  int p[n + 1];

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    p[x] = i;
  }

  for (int i = 1; i <= n; i++) {
    cout << p[i] << ' ';
  }

  return 0;
}