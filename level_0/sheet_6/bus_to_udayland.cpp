#include <iostream>
using namespace std;
using ll = long long;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  bool found_seats = false;

  string a[n];

  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(!found_seats){
      if(a[i][0] == a[i][1] && a[i][0] == 'O'){
        found_seats = true;
        a[i][0] = a[i][1] = '+';
      } else if (a[i][3] == a[i][4] && a[i][3] == 'O'){
        found_seats = true;
        a[i][3] = a[i][4] = '+';
      }
    }
  }

  if(found_seats){
    cout << "YES\n";
    for(int i = 0; i < n; i++){
      cout << a[i] << '\n';
    }
  } else{
    cout << "NO\n";
  }

  return 0;
}