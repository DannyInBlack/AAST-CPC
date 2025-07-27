#include <bits/stdc++.h>
using namespace std;
 
constexpr int N = int(1e3) + 5;
 
int a[N][N], b[N][N];
string s;

void add(int x, int y){
    int z = b[x][y] ? -1 : 1;
    b[x][y] ^= 1;
    for(int i = x; i < N; i += i & -i){
        for(int j = y; j < N; j += j & -j){
            a[i][j] += z;
        }
    }
}
int sum(int x, int y){
    int ans = 0;
    for(int i = x; i; i -= i & -i){
        for(int j = y; j; j -= j & -j){
            ans += a[i][j];
        }
    }
    return ans;
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			char c;
			cin >> c;
			if(c == '*'){
				b[i][j] = 1;
				add(i, j);
			}
		}
	}
	for(int i = 0; i < q; i++){
		int t, x, y, x2, y2;
		cin >> t >> x >> y;
		if(t == 1) add(x, y);
		else{
			cin >> x2 >> y2;
			cout << sum(x2, y2) - sum(x2, y - 1) - sum(x - 1, y2) + sum(x - 1, y - 1) << '\n';
		}
	}

}
