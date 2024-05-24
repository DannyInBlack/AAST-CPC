#include <iostream>
using namespace std;
using ll = long long;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  /*
    One fast way to solve this problem is with binary search
    This allows for a O(log(10^18)) solution
  */

  ll x;
  cin >> x;

  ll l = 0, r = 1e10;

  while(l + 1 < r){
    ll mid = (l + r) / 2;
    if(mid * (mid + 1) / 2 > x){
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << l;

  return 0;
}