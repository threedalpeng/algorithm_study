#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, x, y, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> x >> y >> k;
        ll i = (k * (y + 1));
        cout << (i + x - 3) / (x - 1) + k << '\n';
    }
}