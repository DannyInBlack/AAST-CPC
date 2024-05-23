#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // we'll use the % operation to help us

  int n;
  cin >> n;

  ll p[n];
  bool lucky[n]; // lucky[i] is whether p[i] is lucky or not

  int cnt = 0; // count of lucky numbers

  for(int i = 0; i < n; i++){
    cin >> p[i];

    ll x = p[i]; // so we don't modify the original number
    lucky[i] = x != 0; // assume it's lucky until proven otherwise
  
    while(x){
      if(x % 10 != 4 && x % 10 != 7) {
        lucky[i] = false;
      }
      x /= 10;
    }

    if(lucky[i]){
      cnt++;
    }
  }

  // now output all lucky numbers
  cout << cnt << '\n';

  for(int i = 0; i < n; i++){
    if(lucky[i]){
      cout << p[i] << ' ';
    }
  }

  return 0;
}