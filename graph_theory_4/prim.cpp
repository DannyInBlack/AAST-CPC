#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e5) + 5;

bool vis[N];
vector<pair<int, int>> v[N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y, w;
        cin >> x >> y >> w;

        v[x].push_back({w, y});
        v[y].push_back({w, x});
    }
    ll ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vis[1] = 1;
    for(auto& i : v[1]) q.push(i);
    while(q.size()){
        auto [w, x] = q.top();
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        ans += w;
        for(auto& i : v[x]) q.push(i);
    }
    if(count(vis, vis + n + 1, 1) == n) cout << ans;
    else cout << "IMPOSSIBLE";
}