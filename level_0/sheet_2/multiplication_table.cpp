#include <iostream>
using namespace std;

int main(){

  /*
    Example of problems with misleading question:
    The multiplication table clearly shows from 1 to 12,
    but the example outputs start from 0 to 12.
    We always follow the example output.
  */
  long long n;
  cin >> n;

  for(int i = 0; i <= 12; i++){
    cout << n << " * " << i << " = " << n * i << endl;
  }

  return 0;
}