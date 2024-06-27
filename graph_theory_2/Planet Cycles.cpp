#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 1;

int nxt[N], ans[N];
bool vis[N], cyc[N];

vector<int> v;
void dfs(int x) {
  vis[x] = 1;
  v.push_back(x);
  if (!vis[nxt[x]])
    dfs(nxt[x]);
  else {
    v.erase(v.begin(), find(v.begin(), v.end(), nxt[x]));
    for (auto& i : v) {
      cyc[i] = 1;
      ans[i] = v.size();
    }
  }
}
void dfs2(int x) {
  vis[x] = 1;
  if (!vis[nxt[x]] && !cyc[nxt[x]]) dfs2(nxt[x]);
  ans[x] = 1 + ans[nxt[x]];
}
int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      v.clear();
    }
  }
  fill(vis, vis + N, 0);
  for (int i = 1; i <= n; i++) {
    if (!vis[i] && !cyc[i]) dfs2(i);
    cout << ans[i] << ' ';
  }

  return 0;
}