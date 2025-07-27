#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct node{
	int sum = 0, cl = 0, cr = 0;
};
vector<node> v(1);

void push(int i){
	if(!v[i].cl){
		v[i].cl = v.size();
		v.push_back({});
	}
	if(!v[i].cr){
		v[i].cr = v.size();
		v.push_back({});
	}
}
void update(int x, int p, int l = 0, int r = 1e9, int i = 0){
	if(l > p || p > r) return;
	if(l == r){
		v[i].sum += x;
		return;
	}
	push(i);
	int m = l + r >> 1;
	update(x, p, l, m, v[i].cl);
	update(x, p, m + 1, r, v[i].cr);
	v[i].sum = v[v[i].cl].sum + v[v[i].cr].sum;
}
int query(int L, int R, int l = 0, int r = 1e9, int i = 0){
	if(l > R || r < L) return 0;
	if(l >= L && r <= R){
		return v[i].sum;
	}
	push(i);
	int m = l + r >> 1;
	return query(L, R, l, m, v[i].cl) +
		query(L, R, m + 1, r, v[i].cr);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	update(50, 5);
	update(10, 2e8);
	cout << query(5, 5) << '\n';
	cout << query(4, 4) << '\n';
	cout << query(2, 1e7) << '\n';
	cout << query(1e7, 1e9) << '\n';
	cout << query(1, 1e9) << '\n';
	cout << v.size();
}
