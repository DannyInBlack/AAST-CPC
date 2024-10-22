#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = int(1e9) + 7;
int dp[int(1e6) + 1];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;

    int a[n];
    for(auto& i : a) cin >> i;
    sort(a, a + n);
    dp[0] = 1;
    for(int j = 0; j < x; ++j){
        for(auto& i : a){
            if(i + j > x) break;
            dp[i + j] += dp[j];
            if(dp[i + j] >= MOD) dp[i + j] -= MOD;
        }
    }
    cout << dp[x];
}