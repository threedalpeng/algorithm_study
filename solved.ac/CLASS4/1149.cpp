// RGB 거리
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, r, g, b;
struct rgb {
    int r, g, b;
};
vector<rgb> v, dp;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> r >> g >> b;
        v[i] = { r, g, b };
    }

    dp.resize(N);
    dp[0] = v[0];
    for (int i = 1; i < N; i++) {
        dp[i] = { v[i].r + min(dp[i - 1].g, dp[i - 1].b),
                  v[i].g + min(dp[i - 1].r, dp[i - 1].b),
                  v[i].b + min(dp[i - 1].r, dp[i - 1].g) };
    }

    cout << min(min(dp[N - 1].r, dp[N - 1].g), dp[N - 1].b) << '\n';
}