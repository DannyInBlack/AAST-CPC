#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e6) + 5;

int d[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; ++i){
        for(int j = i; j < N; j += i){
            ++d[j];
        }
    }
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << d[x] << '\n';
    }
}