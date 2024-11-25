#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200005;
int rt[N], sz[N], ans[N];
vector<array<int, 3>> v[N], a[N];
vector<pair<int, int>> e;

int root(int x){
    if(x == rt[x]) return x;
    return rt[x] = root(rt[x]);
}
bool connected(int x, int y){
    return root(x) == root(y);
}
bool merge(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return 0;
    if(sz[x] > sz[y]) swap(x, y);
    e.push_back({x, y});
    sz[y] += sz[x];
    rt[x] = y;
    return 1;
}
void roll_back(){
    auto [x, y] = e.back();
    rt[x] = x;
    sz[y] -= sz[x];
    e.pop_back();
}
void dfs(int n){
    for(auto& [i, x, y] : a[n]){
        ans[i] = connected(x, y);
    }
    for(auto& [i, x, y] : v[n]){
        bool b = merge(x, y);
        dfs(i);
        if(b) roll_back();
    }
}
int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
    for(int i = 0; i <= n; ++i){
        rt[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < q; ++i){
        int t, k, x, y;
        cin >> t >> k >> x >> y;
        if(t == 0){
            v[k + 1].push_back({i + 1, x, y});
        }
        else a[k + 1].push_back({i, x, y});
    }
    memset(ans, -1, sizeof(ans));
    dfs(0);
    for(int i = 0; i <= q; ++i){
        if(ans[i] != -1) cout << ans[i] << '\n';
    }
}