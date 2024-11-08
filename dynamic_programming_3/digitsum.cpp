#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[16][10], pw[16];

ll sum(ll x){
    if(x < 1) return 0;
    string s = to_string(x);
    reverse(s.begin(), s.end());
    ll ans = 0, prv = 0;
    for(int i = s.size() - 1; ~i; --i){
        s[i] -= '0';
        // 57476, i = 2
        // 57399 -> sum(399) + 400 * (5 + 7)
        if(s[i]) ans += dp[i][s[i] - 1];
        ans += prv * s[i] * pw[i];
        // cout << prv << ' ' << int(s[i]) << ' ' << pw[i] << '\n';
        prv += s[i];
    }
    ans += prv;
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    for(int i = 0; i < 16; ++i){
        // pw[i] = 10^i
        pw[i] = i ? 10 * pw[i - 1] : 1;
        for(int j = 0; j < 10; ++j){
            // dp[i][j] = sum from j00.. to j99.. where XX.. means i digits of X
            dp[i][j] = j * pw[i] + (i ? dp[i - 1][9] : 0);
            // dp[i][j] = sum from 0 to j99.. where XX.. means i digits of X
            if(j) dp[i][j] += dp[i][j - 1];
        }
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll a, b;
        cin >> a >> b;
        cout << sum(b) - sum(a - 1) << '\n';
    }
}