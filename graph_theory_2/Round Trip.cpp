#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 1;

vector<int> adj[N];
bool visited[N];
vector<int> parents;

void dfs(int v, int parent){
  visited[v] = 1;
  parents.push_back(v);

  for(const int& e : adj[v]){
    if(visited[e] && e != parent){
      // we have found a cycle, so we try to reach the end of the
      // cycle and then exit safely
      vector<int> ans{e};
      while(parents.back() != e){
        ans.push_back(parents.back());
        parents.pop_back();
      }
      ans.push_back(e);
      cout << ans.size() << '\n';
      for(const auto& x : ans) cout << x << ' ';
      exit(0);
    }

    if(e != parent) dfs(e, v);
  }

  parents.pop_back();
}

int main(){
  // don't forget fast input //
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      dfs(i, -1);
    }
  }

  cout << "IMPOSSIBLE";


}