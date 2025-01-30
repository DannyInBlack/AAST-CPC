#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(2e5) + 5;

struct fenwick{
    int f[N]{};

    void update(int x, int i){
        for(; i < N; i += i&-i){
            f[i] += x;
        }
    }
    int sum(int i){
        int ans = 0;
        for(; i; i -= i&-i){
            ans += f[i];
        }
        return ans;
    }
    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
} f;

int a[N], b[N], ans[N], prv[N];
vector<array<int, 2>> qr[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; ++i){
        a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    }
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        qr[r].push_back({l, i});
    }
    for(int r = 1; r <= n; ++r){
        f.update(1, r);
        int& pv = prv[a[r]];
        if(pv) f.update(-1, pv);
        pv = r;
        for(auto& [l, i] : qr[r]){
            ans[i] = f.sum(l, r);
        }
    }
    for(int i = 0; i < q; ++i){
        cout << ans[i] << '\n';
    }
}