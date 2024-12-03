#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool vis[100005];
ll d[100005];
vector<pair<int, int>> v[100005];
 
int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back({y, w});
    }
    fill(d, d + n + 1, 2e18);
    d[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({d[1], 1});
    while(q.size()){
        auto [dis, x] = q.top();
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(auto& [i, w] : v[x]){
            if(d[i] > d[x] + w){
                d[i] = d[x] + w;
                q.push({d[i], i});
            }
        }
    }
    for(int i = 1; i <= n; ++i) cout << d[i] << ' ';
}
