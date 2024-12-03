#include <bits/stdc++.h>
using namespace std;
 
int in[100005];
vector<int> v[100005];

// add the smallest not added number as early as possible.
// equivalent to add all its requirements then add it
// problem: how do we do the same for its requirments
// alternative: instead of adding the smallest as early as possible,
//      add the largest as late as possible
// the largest number can only be added at the end if no other numbers require it
// therefore the problem can be described as
//      add the largest not added number 
//      that all numbers it require have been added
//      at the end of the array
// notice here we dont have the same problem with the original approach
// because for any number we add all numbers after it have already been added
// while in the original approach we can know where to place a number
// but we don't know the order of those before it.
int main(){
    ios::sync_with_stdio(0);  
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        v[y].push_back(x);
        in[x]++;
    }
    priority_queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(!in[i]) q.push(i);
    }
    vector<int> ans;
    while(q.size()){
        int x = q.top();
        ans.push_back(x);
        q.pop();
        for(auto& j : v[x]){
            if(!--in[j]) q.push(j);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << ' ';
}
