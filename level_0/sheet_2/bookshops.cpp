#include <iostream>
using namespace std;

int main(){
  
  int n;
  cin >> n;

  // one method, loop from 1 to n
  int sum = 0;
  for(int i = 1; i <= n; i++){
    sum += i;
  }

  // another method, use the formula (why does this work?)
  // int sum = n * (n + 1) / 2;

  cout << sum;

  return 0;
}