// 사다리
#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> v(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> v[i];
        }
        int cnt = 0;
        for (int i = N; i > 1; i--) {
            for (int j = 1; j < i; j++) {
                if (v[j + 1] < v[j]) {
                    ++cnt;
                    int tmp = v[j + 1];
                    v[j + 1] = v[j];
                    v[j] = tmp;
                }
            }
        }
        cout << cnt << '\n';
    }
}