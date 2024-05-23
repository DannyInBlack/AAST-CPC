#include <iostream>
using namespace std;

long long fact(long long n){
  if(n < 2){
    return 1;
  }
  return n * fact(n - 1);
}

int main() {

  /*
    If you're unsure whether to use an int or long long,
    then use a long long. Better to be safe than sorry.
    We will solve this problem using recursion.
  */

  long long n;
  cin >> n;

  cout << fact(n);

  return 0;
}