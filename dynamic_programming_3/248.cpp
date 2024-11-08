#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[248][248];

int main(){
    // freopen("248.in", "r", stdin);
    // freopen("248.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> dp[i][i];
    }
    for(int len = 1; len <= n; ++len){
        for(int l = 0; l + len <= n; ++l){
            int r = l + len - 1;
            for(int i = l; i < r; ++i){
                if(dp[l][i] && dp[l][i] == dp[i + 1][r]){
                    dp[l][r] = dp[l][i] + 1;
                    break;
                }
            }
            ans = max(ans, dp[l][r]);
        }
    }
    cout << ans;
}