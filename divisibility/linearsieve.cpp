#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e6) + 5;

vector<int> p;
int spf[N];

void sieve(){
    spf[1] = 1;
    for(int i = 2; i < N; ++i){
        if(!spf[i]){
            p.push_back(i);
            spf[i] = i;
        }
        for(auto& j : p){
            if(i * j >= N) break;
            spf[i * j] = j;
            if(j == spf[i]) break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int x = 5040;
    while(x > 1){
        cout << spf[x] << ' ';
        x /= spf[x];
    }
}