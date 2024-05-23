#include <iostream>
using namespace std;
using ll = long long;

int main() {
  // don't forget these two lines for fast I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  // similar to for(int i = 0; i < q; i++)
  // only difference is that there is no variable 'i',
  // and q decreases (but we don't care about q)
  while(q--){ 
    int x, y;
    cin >> x >> y;

    // since our array starts from 0 and not from 1
    x--, y--; // convert x and y to zero-based indicies 

    // built in swap function
    swap(a[x], a[y]);

    for(int i = 0; i < n; i++){
      cout << a[i] << ' ';
    }
    cout << '\n'; // similar to endl, but faster to run!
  }

  return 0;
}