#include <iostream>
using namespace std;

int main() {

  // one method, repeated division
  long long n;
  cin >> n;

  // next two lines handle the special case n = 0
  int cnt = 1;
  n /= 10;

  while(n != 0){
    cnt++;
    n /= 10;
  }

  cout << cnt;

  /*
    another method, use a string
    string n;
    cin >> n;

    cout << n.length();
  
  */

  return 0;
}