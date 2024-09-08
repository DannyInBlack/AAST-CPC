#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e6) + 5;

int f[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        ++f[x];
    }
    for(int i = N - 1; i; --i){
        int c = 0;
        for(int j = i; j < N; j += i){
            c += f[j];
        }
        if(c >= 2){
            cout << i;
            return 0;
        }
    }
}