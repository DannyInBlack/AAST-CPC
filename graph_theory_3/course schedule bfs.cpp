#include <bits/stdc++.h>
using namespace std;
 
int in[100005];
vector<int> v[100005];
 
int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        in[y]++;
    }
    vector<int> q;
    for(int i = 1; i <= n; ++i){
        if(!in[i]) q.push_back(i);
    }
    for(int i = 0; i < q.size(); ++i){
        for(auto& j : v[q[i]]){
            if(!--in[j]) q.push_back(j);
        }
    }
    if(q.size() != n) cout << "IMPOSSIBLE";
    else for(auto& i : q) cout << i << ' ';
}