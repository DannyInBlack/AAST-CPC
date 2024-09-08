#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(2e7) + 5;

vector<int> p;
int spf[N], f[N];

void sieve(){
    spf[1] =  1;
    for(int i = 2; i < N; ++i){
        if(!spf[i]){
            p.push_back(i);
            spf[i] = i;
            f[i] = 1;
        }
        for(auto& j : p){
            if(i * j >= N) break;
            spf[i * j] = j;
            f[i * j] = f[i] + (j != spf[i]);
            if(j == spf[i]) break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t;
    cin >> t;
    while(t--){
        int c, d, x;
        cin >> c >> d >> x;
        int ans = 0;
        for(int g = 1; g * g <= x; ++g){
            if(x % g) continue;
            int k = x / g + d;
            if(k % c == 0) ans += 1 << f[k / c];
            k = g + d;
            if(g * g != x && k % c == 0) ans += 1 << f[k / c];
        }
        cout << ans << '\n';
    }
}