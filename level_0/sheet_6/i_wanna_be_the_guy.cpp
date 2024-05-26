#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  // We'll use a boolean array to keep track of whether
  // we can pass a level or not
  
  int n, m, x;
  cin >> n;

  bool p[n + 1]{}; // initializes the array to default value (false)

  cin >> m;

  for(int i = 0; i < m; i++){
    cin >> x;
    p[x] = true;
  }

  cin >> m;

  for(int i = 0; i < m; i++){
    cin >> x;
    p[x] = true;
  }

  for(int i = 1; i <= n; i++){
    if(!p[i]){
      cout << "Oh, my keyboard!\n";
      return 0;
    }
  }

  cout << "I become the guy.\n";
  return 0;
}