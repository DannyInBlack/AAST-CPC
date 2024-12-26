#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(2e5) + 5;
constexpr int MOD = int(1e9) + 7;

int rt[N], sz[N];

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

    int ans = 1;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        if(!connect(x, y)){
            ans += ans;
            if(ans >= MOD) ans -= MOD;
        } 
    }
    cout << ans;
}