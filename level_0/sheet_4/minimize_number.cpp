#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  /*
    It can be shown that the maximum number of operations
    would depend on the minimum number of times that one
    of the numbers could be divided by 2

    So, for every number count the number of times it can
    be divided by 2, and minimize that count
  */

  int n;
  cin >> n;

  int cnt = -1;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int no_of_times = 0;
    while (x % 2 == 0) {
      no_of_times++;
      x /= 2;
    }

    if (cnt == -1 || no_of_times < cnt) {
      cnt = no_of_times;
    }
  }

  cout << cnt;

  return 0;
}