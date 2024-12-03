#include <bits/stdc++.h>
using namespace std;

bool vis[100005];
int dp[100005], par[100005];
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
    memset(dp, 0x87, sizeof(dp));
    dp[1] = 0;
    for(int i = 0; i < n; ++i){
        int x = ans[i];
        for(int& j : v[x]){
            if(dp[j] < dp[x] + 1){
                dp[j] = dp[x] + 1;
                par[j] = x;
            }
        }
    }
    if(dp[n] < 0) cout << "IMPOSSIBLE";
    else {
        ans.clear();
        for(int i = n; i; i = par[i]){
            ans.push_back(i);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(auto& i : ans) cout << i << ' ';
    }
}