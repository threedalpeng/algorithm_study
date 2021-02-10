// 사과나무 / 19539
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

int n, v;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    ll n1 = 0, n2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        n1 += (v % 2);
        n2 += (v / 2);
    }
    ll k = n2 - n1;
    if (k >= 0 && k % 3 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}