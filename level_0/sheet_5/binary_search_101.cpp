#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b, k;
  cin >> a >> b >> k;

  int no_of_steps = 0;

  while (a <= b) {
    no_of_steps++;  // increment number of steps each time we loop
    ll mid = (a + b) / 2;
    if (mid == k) {
      break;
    } else if (mid < k) {
      a = mid + 1;
    } else {
      b = mid - 1;
    }
  }

  cout << no_of_steps;

  return 0;
}