#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll a, b;

ld get(ld x){
	return a / sqrtl(1 + x) + b * x;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	ll l = 0, r = a / b;
	while(r - l > 4){
		ll m = (l + r) / 2;
		if(get(m) < get(m + 1)) r = m;
		else l = m + 1;
	}
	for(ll i = l + 1; i <= r; ++i){
		if(get(i) < get(l)) l = i;
	}
	cout << fixed << setprecision(10) << get(l);
}
