#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e6) + 5;

vector<int> p;
int spf[N], phi[N];

void sieve(){
    spf[1] = phi[1] = 1;
    for(int i = 2; i < N; ++i){
        if(!spf[i]){
            p.push_back(i);
            spf[i] = i;
            phi[i] = i - 1;
        }
        for(auto& j : p){
            if(i * j >= N) break;
            spf[i * j] = j;
            phi[i * j] = phi[i] * (j - (j != spf[i]));
            if(j == spf[i]) break;
        }
    }
}
int euler_totient(int x){
    int ans = 1;
    for(int i = 2; i * i <= x; ++i){
        if(x % i) continue;
        ans *= i - 1;
        x /= i;
        while(x % i == 0){
            x /= i;
            ans *= i;
        }
    }
    if(x > 1) ans *= x - 1;
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    for(int i = 1; i < 100; ++i){
        cout << phi[i] << ' ';
    }
}