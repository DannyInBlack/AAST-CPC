#include <iostream>
using namespace std;

int main() {
  long long x, y, z;
  cin >> x >> y >> z;

  if (z < y && z > x) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}