#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
constexpr int N = int(2e5) + 5;

int lza[N * 4];
ll seg[N * 4], lz[N * 4];

void push(int l, int r, int i){
	int m = l + r >> 1, cl = i << 1, cr = cl + 1;
	if(lza[i]){
		lza[cl] = lza[cr] = lza[i];
		seg[cl] = (m - l + 1ll) * lza[i];
		seg[cr] = ll(r - m) * lza[i];
		lz[cl] = lz[cr] = lza[i] = 0;
	}
	seg[cl] += (m - l + 1ll) * lz[i];
	seg[cr] += ll(r - m) * lz[i];
	lz[cl] += lz[i];
	lz[cr] += lz[i];
	lz[i] = 0;
}
void add(int x, int L, int R, int l, int r, int i){
	if(R < l || r < L) return;
	if(L <= l && r <= R){
		seg[i] += x * (r - l + 1ll);
		lz[i] += x;
		return;
	}
	int m = l + r >> 1, cl = i << 1, cr = cl + 1;
	push(l, r, i);
	add(x, L, R, l, m, cl);
	add(x, L, R, m + 1, r, cr);
	seg[i] = seg[cl] + seg[cr];
}
void assign(int x, int L, int R, int l, int r, int i){
	if(R < l || r < L) return;
	if(L <= l && r <= R){
		seg[i] = x * (r - l + 1ll);
		lza[i] = x;
		lz[i] = 0;
		return;
	}
	int m = l + r >> 1, cl = i << 1, cr = cl + 1;
	push(l, r, i);
	assign(x, L, R, l, m, cl);
	assign(x, L, R, m + 1, r, cr);
	seg[i] = seg[cl] + seg[cr];
}
ll query(int L, int R, int l, int r, int i){
	if(R < l || r < L) return 0;
	if(L <= l && r <= R) return seg[i];
	int m = l + r >> 1, cl = i << 1, cr = cl + 1;
	push(l, r, i);
	return query(L, R, l, m, cl)
		+ query(L, R, m + 1, r, cr);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		assign(x, i, i, 1, n, 1);
	}
	while(q--){
		int t, l, r, x;
		cin >> t >> l >> r;
		if(t != 3) cin >> x;
		if(t == 1) add(x, l, r, 1, n, 1);
		else if(t == 2) assign(x, l, r, 1, n, 1);
		else cout << query(l, r, 1, n, 1) << '\n';
	}
}