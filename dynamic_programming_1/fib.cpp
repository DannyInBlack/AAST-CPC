#include <bits/stdc++.h>
using namespace std;

int f[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= 100; ++i){
        f[i] = f[i - 1] + f[i - 2];
        if(f[i] >= 10000000) f[i] -= 10000000;
        cout << f[i] << ' ';
    }

}