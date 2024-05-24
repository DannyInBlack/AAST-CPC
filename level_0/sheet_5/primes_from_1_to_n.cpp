#include <iostream>
using namespace std;
using ll = long long;

bool prime(int n) {  // prime function but a bit more optimized
  if (n < 2) return false;
  if (n < 4) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  // Use the prime function from earlier

  int n;
  cin >> n;

  for(int i = 2; i <= n; i++){
    if(prime(i)){
      cout << i << ' ';
    }
  }
  
  return 0;
}