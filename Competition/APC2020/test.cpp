#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, c, seed, m, x1, x2;
    cin >> m >> seed >> a >> c;
    // c = m - seed;
    x1 = (a * seed + c) % m;
    x2 = (a * x1 + c) % m;
    cout << x1 << ' ' << x2;
}