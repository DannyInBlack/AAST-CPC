#include <iostream>
using namespace std;

int main(){

  /*
    Summing from 1 to n is equivalent to n * (n + 1) / 2.
    Since n could be 10^6, the output may reach 10^12,
    therefore we should use a long long to avoid overflow
  */

  int n;
  cin >> n;

  long long sum = 0;
  for(int i = 1; i <= n; i++){
    sum += i;
  }

  cout << sum;

  return 0;
}