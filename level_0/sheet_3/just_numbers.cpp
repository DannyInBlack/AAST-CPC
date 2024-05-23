#include <iostream>
using namespace std;

int main() {
  
  // one method, use the % operator
  long long n;
  cin >> n;

  // handles case n = 0
  cout << n % 10 << ' ';
  n /= 10;

  while(n){ // while(n) is the same as while(n != 0)
    cout << n % 10 << ' ';
    n /= 10;
  }

  /*
    Another method, use strings, then print in reverse
    (you could also use the reverse function)

    string n;
    cin >> n;

    for(int i = n.length() - 1; i >= 0; i--){
      cout << n[i] << ' ';
    }
    // or use reverse(s.begin(), s.end()) then print s
  */
  return 0;
}