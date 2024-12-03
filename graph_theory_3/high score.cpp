#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll d[2505];
array<int, 3> e[5005];

int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        auto& [x, y, w] = e[i];
        cin >> x >> y >> w;
    }
    fill(d, d + n + 1, -1e18);
    d[1] = 0;
    for(int i = 0; i <= 2 * n; ++i){
        for(int j = 0; j < m; ++j){
            auto& [x, y, w] = e[j];
            // update y iff x has been updated
            if(d[y] < d[x] + w && d[x] > ll(-1e18)){
                // if you can update an element after the nth iteration:
                // then you can update it infinitely 
                // if so then set it to infinity
                if(i > n) d[y] = ll(1e18);
                else d[y] = d[x] + w;
            }
        }
    }
    if(d[n] >= ll(1e18)) cout << -1;
    else cout << d[n];
}
