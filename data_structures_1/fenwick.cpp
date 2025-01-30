#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(2e5) + 5;

struct fenwick{
    int f[N]{};

    void update(int x, int i){
        for(; i < N; i += i&-i){
            f[i] += x;
        }
    }
    int sum(int i){
        int ans = 0;
        for(; i; i -= i&-i){
            ans += f[i];
        }
        return ans;
    }
    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
    int lower_bound(int x){
        int ans = 0;
        for(int i = __lg(N - 1); ~i; --i){
            int p = ans + (1 << i);
            if(p < N && f[p] < x){
                ans = p;
                x -= f[p];
            }
        }
        return ans + 1;
    }
} f;

int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        f.update(1, i);
    }
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        int p = f.lower_bound(x);
        cout << a[p] << ' ';
        f.update(-1, p);
    }
}