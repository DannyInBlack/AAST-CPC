#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 1;  // from the problem statement

int n, m;
vector<int> adj[N];
vector<int> reverse_adj[N];
bool vis[N];

void dfs(int v) {
  vis[v] = 1;

  for (auto e : adj[v]) {
    if (!vis[e]) {
      dfs(e);
    }
  }
}

void reverse_dfs(int v) {
  vis[v] = 1;

  for (auto e : reverse_adj[v]) {
    if (!vis[e]) {
      reverse_dfs(e);
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    reverse_adj[to].push_back(from);  // reverse the direction of the edges
  }

  dfs(1);  // try to reach every node from node 1
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cout << "NO\n" << 1 << ' ' << i;
      return 0;
    }
    vis[i] = 0;
  }

  reverse_dfs(1);  // try to reach 1 from every node

  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      cout << "NO\n" << i << ' ' << 1;
      return 0;
    }
  }

  cout << "YES";

  return 0;
}