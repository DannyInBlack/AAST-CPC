#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll d[505][505];
 
int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0);
 
    int n, m, q;
    cin >> n >> m >> q;
    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i < m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = d[b][a] = min<ll>(d[a][b], w);
    }
    for(int i = 1; i <= n; ++i) d[i][i] = 0;
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for(int i = 0; i < q; ++i){
        int a, b;
        cin >> a >> b;
        if(d[a][b] > ll(1e18)) cout << "-1\n";
        else cout << d[a][b] << '\n';
    }
}
