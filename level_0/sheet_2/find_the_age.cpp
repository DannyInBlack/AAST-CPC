#include <iostream>
using namespace std;

int main(){
  int y, m, d;
  cin >> y >> m >> d;

  // read problem carefully!
  // each year is 30 months
  // each month is 12 days

  cout << 12 * (y * 30 + m) + d;

  return 0;
}