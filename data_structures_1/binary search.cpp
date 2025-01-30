#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool bin_srch(int x, const vector<int>& v){
    int l = 0, r = v.size() - 1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(v[m] == x) return 1;
        if(v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return 0;
}
bool bin_srch2(int x, const vector<int>& v){
    int curp = 0;
    for(int i = __lg(v.size() - 1); ~i; --i){
        int newp = curp + (1 << i);
        if(newp >= v.size()) continue;
        if(v[newp] == x) return 1;
        if(v[newp] < x) curp = newp;
    }
    return v[curp] == x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(bin_srch2(x, v)) cout << "Yes\n";
        else cout << "No\n";
    }
}