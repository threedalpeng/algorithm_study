// 통계학
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

int n, inputs[500001], frq[9001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    ll sum = 0;
    int mn = 4001, mx = -4001;

    int x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        inputs[i] = x;
        sum += x;
        ++frq[x + 4000];
        if (x < mn) mn = x;
        if (x > mx) mx = x;
    }
    sort(inputs + 1, inputs + n + 1);

    ll mean = round(static_cast<double>(sum) / static_cast<double>(n));
    int mid = inputs[(n + 1) / 2];
    int mod_f = 0;
    int mod_n[2] = { -1, -1 };
    for (int i = 0; i <= 9000; i++) {
        if (frq[i] == mod_f && mod_n[1] == -1) {
            mod_n[1] = i;
        }
        else if (frq[i] > mod_f) {
            mod_n[0] = i;
            mod_n[1] = -1;
            mod_f = frq[i];
        }
    }
    cout << mean << '\n';
    cout << mid << '\n';
    cout << (mod_n[1] == -1 ? mod_n[0] - 4000 : mod_n[1] - 4000) << '\n';
    cout << mx - mn;
}