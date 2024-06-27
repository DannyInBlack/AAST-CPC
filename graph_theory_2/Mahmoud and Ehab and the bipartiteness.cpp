#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 1;

vector<int> adj[N];
long long cnt1, cnt2;

void dfs(int vertix, int parent, bool color) {
  color ? cnt2++ : cnt1++;

  for (const int& e : adj[vertix]) {
    if (e != parent) {
      dfs(e, vertix, !color);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  // tree has n - 1 edges
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, -1, 0);

  cout << cnt1 * cnt2 - (n - 1);

  return 0;
}