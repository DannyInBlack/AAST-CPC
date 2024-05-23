#include <iostream>
using namespace std;

int main(){
  // one way to solve this, use a string

  string x;
  cin >> x;

  cout << x[0];

  // another way
  /*
    int x;
    cin >> x;
    cout << x % 10000; // why does this work?
  */

  return 0;
}