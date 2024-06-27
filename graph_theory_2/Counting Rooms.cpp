#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool vis[1001][1001];
string s[1001];

bool inbounds(int x, int y){
  return x >= 0 && y >= 0 && x < n && y < m;
}
void dfs(int x, int y){
  vis[x][y] = 1;
  for(int i = 0; i < 4; ++i){
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if(inbounds(x2, y2) && s[x2][y2] == '.' && !vis[x2][y2]){
      dfs(x2, y2);
    } 
  }
}
void solve(){
  cin >> n >> m; 
  for(int i = 0; i < n; ++i){
    cin >> s[i];
  }
  int ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(!vis[i][j] && s[i][j] == '.'){
        dfs(i, j);
        ans++;
      }
    }
  }
  cout << ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}