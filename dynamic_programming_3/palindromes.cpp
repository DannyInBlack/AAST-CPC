#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 5000;
int dp[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    string s;
    int q;
    cin >> s >> q;
    // s[l..r] is pal if s[l] == s[r] and s[l+1...r-1] is pal
    for(int i = 0; i < s.size(); ++i){
        for(int j = 0; j < 2; ++j){
            for(int l = i, r = i + j; l >= 0 && r < s.size() && s[l] == s[r]; --l, ++r){
                dp[l][r] = 1;
            }
        }
    }
    for(int len = 2; len <= s.size(); ++len){
        for(int l = 0; l + len <= s.size(); ++l){
            int r = l + len - 1;
            dp[l][r] += dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
        }
    }
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        cout << dp[l - 1][r - 1] << '\n';
    }
}