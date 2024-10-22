#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = int(1e9) + 7;
int dp[int(1e6) + 1];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;

    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        int c;
        cin >> c;
        for(int j = c; j <= x; ++j){
            dp[j] += dp[j - c];
            if(dp[j] >= MOD) dp[j] -= MOD;
        }
    }
    cout << dp[x];
}