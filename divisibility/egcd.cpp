#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// g, x, y
array<int, 3> egcd(int a, int b){
    if(!a) return {b, 0, 1};
    int k = b / a;
    auto [g, x, y] = egcd(b - k * a, a);
    return {g, y - k * x, x};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a = 15, b = 7;
    auto [g, x, y] = egcd(a, b);
    cout << "gcd: " << g << '\n';
    cout << "combinations to get gcd:\n";
    cout << a << '*' << x << " + " << b << '*' << y << '\n';
}