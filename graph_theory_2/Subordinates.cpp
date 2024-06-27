#include <bits/stdc++.h>
using namespace std;

int sub[int(2e5) + 1];
vector<int> child[int(2e5) + 1];

void dfs(int x){
  for(auto& i : child[x]){
    dfs(i);
    sub[x] += 1 + sub[i];
  }
}
int main() {
  int n;
  cin >> n;
  for(int i = 2; i <= n; ++i){
    int par;
    cin >> par;
    child[par].push_back(i);
  }
  dfs(1);
  for(int i = 1; i <= n; ++i){
    cout << sub[i] << ' ';
  }
 
 return 0;
}