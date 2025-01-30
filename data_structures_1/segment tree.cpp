#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
constexpr int N = int(2e5) + 5;
 
int n, b[N];
 
struct segtree{
    int a[N * 4];
 
    int id(){
        return 2e9;
    }
    int merge(int l, int r){
        return min(l, r);
    }
    void init(int l = 1, int r = n, int i = 1){
        if(l == r){
            a[i] = b[l];
            return;
        }
        int m = (l + r) >> 1, cl = i<<1, cr = cl + 1;
        init(l, m, cl);
        init(m + 1, r, cr);
        a[i] = merge(a[cl], a[cr]);
    }
    void update(int x, int p, int l = 1, int r = n, int i = 1){
        if(p < l || p > r) return;
        if(l == r){
            a[i] = x;
            return;
        }
        int m = (l + r) >> 1, cl = i<<1, cr = cl + 1;
        update(x, p, l, m, cl);
        update(x, p, m + 1, r, cr);
        a[i] = merge(a[cl], a[cr]);
    }
    int query(int L, int R, int l = 1, int r = n, int i = 1){
        if(r < L || l > R) return id();
        if(L <= l && r <= R) return a[i];
        int m = (l + r) >> 1, cl = i<<1, cr = cl + 1;
        return merge(query(L, R, l, m, cl),
            query(L, R, m + 1, r, cr));
    }
} seg;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    seg.init();
 
    while(q--){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) seg.update(b, a);
        else cout << seg.query(a, b) << '\n';
    }
}