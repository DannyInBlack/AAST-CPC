#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1001;

struct segtree{
	int sm[N * 4];
	void update(int d, int x, int l = 1, int r = N - 1, int i = 1){
		if(x > r || x < l) return;
		if(l == r){
			sm[i] += d;
			return;
		}
		sm[i] += d;
		int m = l + r >> 1, cl = i << 1, cr = cl + 1;
		update(d, x, l, m, cl);
		update(d, x, m + 1, r, cr);
	}
	int query(int xl, int xr, int l = 1, int r = N - 1, int i = 1){
		if(xl > r || xr < l) return 0;
		if(xl <= l && r <= xr) return sm[i];
		int m = l + r >> 1, cl = i << 1, cr = cl + 1;
		return query(xl, xr, l, m, cl) +
			query(xl, xr, m + 1, r, cr);
	}
} seg[N * 4];

void update(int d, int x, int y, int l = 1, int r = N - 1, int i = 1){
	if(y > r || y < l) return;
	seg[i].update(d, x);
	if(l == r) return;
	int m = l + r >> 1, cl = i << 1, cr = cl + 1;
	update(d, x, y, l, m, cl);
	update(d, x, y, m + 1, r, cr);
}
int query(int xl, int xr, int yl, int yr, int l = 1, int r = N - 1, int i = 1){
	if(yl > r || yr < l) return 0;
	if(yl <= l && r <= yr) return seg[i].query(xl, xr);
	int m = l + r >> 1, cl = i << 1, cr = cl + 1;
	return query(xl, xr, yl, yr, l, m, cl) +
		query(xl, xr, yl, yr, m + 1, r, cr);
}
bool b[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			char c;
			cin >> c;
			if(c == '*'){
				b[i][j] = 1;
				update(1, i, j);
			}
		}
	}
	while(q--){
		int t, x, y, x2, y2;
		cin >> t >> x >> y;
		if(t == 1){
			int d = 1;
			if(b[x][y]) d = -1;
			b[x][y] ^= 1;
			update(d, x, y);
		}
		else{
			cin >> x2 >> y2;
			cout << query(x, x2, y, y2) << '\n';
		}
	}
}
