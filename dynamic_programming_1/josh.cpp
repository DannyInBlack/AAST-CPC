#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, bool m){
    int r = n + m >> 1;
    if(r >= k) return k * 2 - m;
    return 2 * solve(n - r, k - r, (n & 1) ^ m) - !m;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << solve(n, k, 0) << '\n';
    }
}