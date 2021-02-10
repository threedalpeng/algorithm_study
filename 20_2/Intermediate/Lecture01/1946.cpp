#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int T, N;
vector<pii> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        int a, b;
        v.clear();
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        sort(v.begin(), v.end());
        int mn = 1e9, cnt = 0;
        for (int i = 0; i < N; i++) {
            if (mn > v[i].second) {
                mn = v[i].second;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}