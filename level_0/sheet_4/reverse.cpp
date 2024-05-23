#include <iostream>
using namespace std;
using ll = long long;

int main() {

  // welcome to sheet 4
  // we'll add a few more things to our template
  // use (using ll = long long) to rename long long to ll
  // (you could name any datatype whatever you want, 
  // this makes it easier to type)
  // the next 2 lines optimize our input and output
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int a[n]; // allocating an array of size n (0 to n - 1)
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    cout << a[i] << ' ';
  }

  return 0;
}