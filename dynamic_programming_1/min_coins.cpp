#include <bits/stdc++.h>
using namespace std;

int dp[int(1e6) + 1];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    fill(dp, dp + x + 1, int(1e9));

    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        int c;
        cin >> c;
        for(int j = c; j <= x; ++j){
            dp[j] = min(dp[j], dp[j - c] + 1);
        }
    }
    if(dp[x] == int(1e9)) cout << -1;
    else cout << dp[x];
}