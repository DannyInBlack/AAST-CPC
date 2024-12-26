#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(2e5) + 5;

int rt[N], sz[N];
array<int, 3> a[N];

int root(int x){
    if(x == rt[x]) return x;
    return rt[x] = root(rt[x]);
}
bool connect(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return 0;
    if(sz[x] > sz[y]) swap(x, y);
    sz[y] += sz[x];
    rt[x] = y;
    return 1;
}
int main(){
    int n, m;
    cin >> n >> m;
    iota(rt, rt + N, 0);
    fill(sz, sz + N, 1);

    for(int i = 0; i < m; ++i){
        cin >> a[i][1] >> a[i][2] >> a[i][0];
    }
    sort(a, a + m);

    ll ans = 0;
    for(int i = 0; i < m; ++i){
        auto& [w, x, y] = a[i];
        if(connect(x, y)){
            ans += w;
            --n;
        } 
    }
    if(n == 1) cout << ans;
    else cout << "IMPOSSIBLE";
}