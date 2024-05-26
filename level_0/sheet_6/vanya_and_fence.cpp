#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // width initially is n, increase width when a person is taller than the
  // fence's height

  int n, h;
  cin >> n >> h;

  int width = n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > h) width++;
  }

  cout << width;

  return 0;
}