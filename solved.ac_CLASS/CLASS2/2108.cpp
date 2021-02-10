// 통계학
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int n, a[500001], mode[9001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    int sum = 0, mid;
    int mn = 4001, mx = -4001;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        ++mode[a[i] + 4000];
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }
    sort(a + 1, a + n + 1);
    mid = a[(n + 1) / 2];
    int mod_f = 0;
    int mod_n[2] = { -1, -1 };
    for (int i = 0; i <= 9000; i++) {
        if (mode[i] == mod_f && mod_n[1] == -1) {
            mod_n[1] = i;
        }
        else if (mode[i] > mod_f) {
            mod_n[0] = i;
            mod_n[1] = -1;
            mod_f = mode[i];
        }
    }
    cout << round(sum / static_cast<double>(n)) << '\n';
    cout << mid << '\n';
    cout << (mod_n[1] == -1 ? mod_n[0] - 4000 : mod_n[1] - 4000) << '\n';
    cout << mx - mn;
}