#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, ans = 0;
    cin >> n;
    for(ll i = 2; i * i <= n; ++i){
        int c = 0;
        while(n % i == 0){
            ++c;
            n /= i;
        }
        for(int j = 1; j <= c; ++j){
            c -= j;
            ++ans;
        }
    }
    cout << ans + (n > 1);
}