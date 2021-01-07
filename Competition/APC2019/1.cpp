#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    int n, l, k;
    pii prb[100];
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++) {
        cin >> prb[i].second >> prb[i].first;
    }
    sort(prb, prb + n);
    int sum = 0, cnt = 0;
    for (int i = 0; i < k; i++) {
        if (prb[i].first <= l) {
            sum += 140;
            cnt++;
        }
        else if (prb[i].second <= l) {
            sum += 100;
            cnt++;
        }
    }
    if (cnt != k) {
        for (int i = k; i < n; i++) {
            if (prb[i].second <= l) {
                sum += 100;
                cnt++;
            }
            if (cnt == k) break;
        }
    }
    cout << sum << endl;
}