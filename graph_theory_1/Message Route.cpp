// https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  int n, m; cin >> n >> m;
  vector<int> adjacent[n + 1];
  bool visited[n + 1]{};
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adjacent[a].push_back(b);
    adjacent[b].push_back(a);
  }

  int parent[n + 1]{}; // keep track of parent nodes of each node
  parent[1] = -1; // since we dfs from the first one, it has no parent
 
  // initialize BFS
  queue<int> q; 
  q.push(1);
  visited[1] = 1;
  while(!q.empty()){
    int current = q.front();
    q.pop();
    if(current == n){ // Reached the final computer
      break;
    }
    for(auto e : adjacent[current]){
      if(!visited[e]){
        visited[e] = 1;
        parent[e] = current; // if we go from 1 to 2, then 1 is the parent of 2
        q.push(e);
      }
    }
  }
 
  if(parent[n] == 0){ // Didn't reach the final computer
    cout << "IMPOSSIBLE";
    return 0;
  }
 
  vector<int> ans;
  int i = n;
  ans.push_back(n);
  while(parent[i] != -1){ // Traverse the path till we reach the first node
    ans.push_back(parent[i]);
    i = parent[i];
  }
 
  reverse(ans.begin(), ans.end()); // Reverse it so it is in order from 1 to N
  cout << ans.size() << '\n';
  for(const auto& x : ans){
    cout << x << ' ';
  }
 
  return 0;
}