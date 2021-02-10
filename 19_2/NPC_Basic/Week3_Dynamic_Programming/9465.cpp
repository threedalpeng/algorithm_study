// 스티커
#include <algorithm>
#include <iostream>
using namespace std;

int T, n, stk[2][100'001], DP[3][100'001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= 1; i++)
            for (int j = 1; j <= n; j++)
                cin >> stk[i][j];
        DP[0][1] = stk[0][1];
        DP[1][1] = stk[1][1];
        DP[2][1] = max(DP[0][1], DP[1][1]);
        for (int i = 2; i <= n; i++) {
            DP[0][i] = max(DP[1][i - 1], DP[2][i - 2]) + stk[0][i];
            DP[1][i] = max(DP[0][i - 1], DP[2][i - 2]) + stk[1][i];
            DP[2][i] = max(DP[0][i], DP[1][i]);
            // cout << DP[0][i] << ' ' << DP[1][i] << ' ' << DP[2][i] << '\n';
        }
        cout << DP[2][n] << '\n';
    }
}