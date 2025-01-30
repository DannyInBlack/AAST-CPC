#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(2e5) + 5;

int n;

struct segtree{
    int cnt[N * 4];

    int merge(int l, int r){
        return l + r;
    }
    void init(int l = 1, int r = n, int i = 1){
        if(l == r){
            cnt[i] = 1;
            return;
        }
        int m = (l + r) >> 1, cl = i<<1, cr = cl + 1;
        init(l, m, cl);
        init(m + 1, r, cr);
        cnt[i] = merge(cnt[cl], cnt[cr]);
    }
    int query(int k, int l = 1, int r = n, int i = 1){
        if(l == r){
            cnt[i] = 0;
            return l;
        } 
        int ans, m = (l + r) >> 1, cl = i<<1, cr = cl + 1;
        if(cnt[cl] >= k) ans = query(k, l, m, cl);
        else ans = query(k - cnt[cl], m + 1, r, cr);
        cnt[i] = merge(cnt[cl], cnt[cr]);
        return ans;
    }
} seg;

int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    seg.init();

    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        cout << a[seg.query(x)] << ' ';
    }
}