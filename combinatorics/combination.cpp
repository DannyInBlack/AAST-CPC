#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C[20 + 1][20 + 1];
    for(int i = 0; i <= 20; ++i){
        C[i][i] = C[i][0] = 1;
    }
    for(int i = 1; i <= 20; ++i){
        for(int j = 1; j < i; ++j){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    for(int i = 0; i <= 20; ++i){
        for(int j = 0; j <= i; ++j){
            cout << C[i][j] << ' ';
        }
        cout << '\n';
    }

    long long f[20 + 1]{1};
    for(int i = 1; i <= 20; ++i){
        f[i] = f[i - 1] * i;
    }
    for(int i = 0; i <= 20; ++i){
        for(int j = 0; j <= i; ++j){
            cout << f[i] / (f[j] * f[i - j]) << ' ';
        }
        cout << '\n';
    }
}