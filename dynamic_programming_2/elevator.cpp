#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 20;

int a[N];
pair<int, int> dp[1 << N]; // number of ride, current weight

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 1; i < (1 << n); ++i){
        if(__builtin_popcount(i) == 1){
            dp[i] = {0, a[__builtin_ctz(i)]};
            continue;
        } 
        dp[i] = {1e9, 0};
        for(int j = 0; j < n; ++j){
            if((i >> j) & 1){
                auto p = dp[i ^ (1 << j)];
                if(p.second + a[j] > x){
                    p.first++;
                    p.second = 0;
                }
                p.second += a[j];
                dp[i] = min(dp[i], p);
            }
        }
    }
    cout << 1 + dp[(1 << n) - 1].first;
}