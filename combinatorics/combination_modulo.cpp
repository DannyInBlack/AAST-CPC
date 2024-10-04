#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e6 + 5;
constexpr int MOD = 1e9 + 7;

int f[N], fi[N];

int fpow(int x, int p){
    int r = 1;
    while(p){
        if(p & 1) r = ll(r) * x % MOD;
        x = ll(x) * x % MOD;
        p >>= 1;
    }
    return r;
}
int c(int n, int k){
    return f[n] * ll(fi[n - k]) % MOD * fi[k] % MOD; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    f[0] = 1;
    for(int i = 1; i < N; ++i){
        f[i] = ll(i) * f[i - 1] % MOD;
    }
    fi[N - 1] = fpow(f[N - 1], MOD - 2);
    for(int i = N - 1; i; --i){
        fi[i - 1] = ll(fi[i]) * i % MOD; 
    }
    for(int i = 0; i < q; ++i){
        int n, k;
        cin >> n >> k;
        cout << c(n, k) << '\n';
    }
}