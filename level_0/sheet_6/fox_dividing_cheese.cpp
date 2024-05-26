#include <iostream>
using namespace std;
using ll = long long;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  /*
    Based on prime factorization:
    We make the two numbers equal by dividing by 2, 
    3, and 5 until we can't divide anymore
    If the numbers are not yet equal, then there is 
    no way to make them equal.
    If the numbers are equal, then the number of moves is
    the difference of the total times they were divided 
    by 2, 3, and 5
  */
  
  int a, b;
  cin >> a >> b;
 
  int factors_of_a[3] = {}, factors_of_b[3] = {};
 
  for(auto i : {2, 3, 5}){
    while(a % i == 0){
      factors_of_a[(i - 1) / 2]++;
      a /= i;
    }
  }
 
  for(auto i : {2, 3, 5}){
    while(b % i == 0){
      factors_of_b[(i - 1) / 2]++;
      b /= i;
    }
  }
 
  if(a != b){
    cout << -1;
    return 0;
  }
 
  int ans = 0;
 
  for(int i = 0; i < 3; i++){
    ans += abs(factors_of_a[i] - factors_of_b[i]);
  }

  cout << ans;

  return 0;
}