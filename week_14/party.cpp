// https://codeforces.com/contest/115/problem/A
// Bonus: This code is O(n^2), could you find a better way?
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2000];

int dfs(int u){
  int count = 0;
  for(auto v : adj[u]){
    count = max(dfs(v), count); // maximum value of the connected branches
  }
  return 1 + count;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n;
  
  // graph input
  for(int i = 0; i < n; i++){
    cin >> x;
    if(x != -1){ // put the child node in the parent's list
      adj[--x].push_back(i);
    }
  }
 
  int count = 0;
  for(int i = 0; i < n; i++){
    count = max(dfs(i), count); // maximize the value of the longest branch
  }
  cout << count;

  return 0;
}