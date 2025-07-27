#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct node{
	int a[2]{}, cnt{};
};
vector<node> v(1);

void update(int d, int x){
	int t = 0;
	for(int i = 29; ~i; --i){
		int b = (x >> i) & 1;
		if(!v[t].a[b]){
			v[t].a[b] = v.size();
			v.push_back({});
		}
		t = v[t].a[b];
		v[t].cnt += d;
	}
}
int query(int x){
	int t = 0, ans = 0;
	for(int i = 29; ~i; --i){
		int b = (x >> i) & 1;
		if(v[v[t].a[!b]].cnt){
			ans += 1 << i;
			t = v[t].a[!b];
		}
		else t = v[t].a[b];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	update(1, 0);
	while(q--){
		char c;
		int x;
		cin >> c >> x;
		if(c == '+') update(1, x);
		else if(c == '-') update(-1, x);
		else cout << query(x) << '\n';
	}
}
