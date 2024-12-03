#include <bits/stdc++.h>
using namespace std;

bool vis[100005];
int pos[100005];
vector<int> v[100005], ans;

void dfs(int x){
    vis[x] = 1;
    for(int& i : v[x]){
        if(!vis[i]) dfs(i);
    }
    ans.push_back(x);
}
int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]) dfs(i);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n; ++i){
        pos[ans[i]] = i; 
    }
    for(int i = 1; i <= n; ++i){
        for(auto& j : v[i]){
            if(pos[j] <= pos[i]){
                cout << "IMPOSSIBLE";
                return 0;
            }
        } 
    }
    for(auto& i : ans) cout << i << ' ';
}