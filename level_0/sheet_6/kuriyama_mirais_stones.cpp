#include <algorithm>  // for sort function
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  /*
    two arrays, one sorted and other normal.
    preform a prefix sum operation on the normal and sorted array.
    for more on prefix sum:
    https://www.youtube.com/watch?v=PhgtNY_-CiY
  */

  int n;
  cin >> n;

  ll normal[n], sorted[n];
  for (int i = 0; i < n; i++) {
    cin >> normal[i];
    sorted[i] = normal[i];
  }

  sort(sorted, sorted + n);  // sort(begin, end) function, sorts from begin to
                             // end (by default: ascending order)

  for(int i = 1; i < n; i++){ // prefix sum operation
    normal[i] += normal[i - 1];
    sorted[i] += sorted[i - 1];
  }

  int queries;
  cin >> queries;

  while(queries--){
    int type, l, r;
    cin >> type >> l >> r;
    r--, l--;

    ll ans;

    if(type == 1){
      ans = normal[r];
      if(l > 0) ans -= normal[l - 1];
    } else {
      ans = sorted[r];
      if(l > 0) ans -= sorted[l - 1];
    }

    cout << ans << '\n';
  }

  return 0;
}