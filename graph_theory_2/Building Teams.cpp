#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 1;

vector<int> adj[N];
bool vis[N];
int color[N];

void dfs(int v, int c){
  color[v] = c;
  vis[v] = true;

  for(const int& e : adj[v]){
    if(!vis[e]){
      dfs(e, c == 1 ? 2 : 1);
    } else if(color[e] == c){
      // If we find an already visited node with the same color
      // then it is impossible to create two teams
      cout << "IMPOSSIBLE";
      exit(0);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // input
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      dfs(i, 1);
    }
  }

  for(int i = 1; i <= n; i++){
    cout << color[i] << ' ';
  }
}