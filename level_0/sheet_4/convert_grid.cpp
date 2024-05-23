#include <iostream>
using namespace std;
using ll = long long;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  /*
    Since in each operation we remove a number from A 
    and then replace it by one of its divisors, if we 
    want to convert A to B, then we should check if each 
    number in B is a divisor of its respective number in A.
  */
  
  int n, m;
  cin >> n >> m;

  ll a[n][m];
  ll b[n][m];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> b[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] % b[i][j] != 0){
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES";
  return 0;
}