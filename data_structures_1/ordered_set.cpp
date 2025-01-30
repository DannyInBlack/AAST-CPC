#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ordered_set<pair<int, int>> s;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        s.insert({i, x});
    }
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        auto it = s.find_by_order(x - 1);
        cout << it->second << ' ';
        s.erase(it);
    }
}