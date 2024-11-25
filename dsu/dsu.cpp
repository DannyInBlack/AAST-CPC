#include <bits/stdc++.h>
using namespace std;

int rt[200005], sz[200005], ans = 0;

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
    sz[y] += sz[x];
    ans = max(ans, sz[y]);
    rt[x] = y;
    return 1;
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
    while(q--){
        int x, y;
        cin >> x >> y;
        n -= merge(x, y);
        cout << n << ' ' << ans << '\n';
    }
}