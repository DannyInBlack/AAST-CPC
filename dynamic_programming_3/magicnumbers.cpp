#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr int N = int(2e3) + 5;
constexpr int MOD = int(1e9) + 7;

int m, d, dp[N][N], pw[N];
string a, b;

int sub(int x, const int& y){
    x -= y;
    while(x < 0) x += m;
    return x;
}
int get(int p, int mod, bool l, bool r){
    if(p == a.size()) return !mod;
    int il = l ? a[p] - '0' : 0;
    int ir = r ? b[p] - '0' : 9;
    bool bl = (il != d) ^ (p & 1);
    bool br = (ir != d) ^ (p & 1);
    if(il == ir) return bl ? get(p + 1, sub(mod, il * pw[p]), l, r) : 0;
    int ans = l && bl ? get(p + 1, sub(mod, il * pw[p]), l, 0) : 0;
    ans += r && br ? get(p + 1, sub(mod, ir * pw[p]), 0, r) : 0;
    if(ans >= MOD) ans -= MOD;
    for(int i = il + l; i <= ir - r; ++i){
        if((i != d) ^ (p & 1)){
            ans += dp[p + 1][sub(mod, i * pw[p])];
            if(ans >= MOD) ans -= MOD;
        } 
    }
    return ans;
}
void solve(){
    cin >> m >> d >> a >> b;
    dp[a.size()][0] = 1;
    for(int i = a.size() - 1, p = 1; ~i; --i, p = p * 10 % m){
        for(int j = 0; j < m; ++j){
            if(i & 1) dp[i][j] = dp[i + 1][sub(j, d * p)];
            else for(int k = 0; k < 10; ++k){
                if(k != d) dp[i][j] += dp[i + 1][sub(j, k * p)];
                if(dp[i][j] >= MOD) dp[i][j] -= MOD;
            }
        }
        pw[i] = p;
    }
    cout << get(0, 0, 1, 1);
    // 12345: a
    // 12678: b
    // 12 [3-6]
    //   3 l = 1, r = 0
    //   6 l = 0, r = 1
    //   [4-5] dp for loop
}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);    
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve();
    }
}