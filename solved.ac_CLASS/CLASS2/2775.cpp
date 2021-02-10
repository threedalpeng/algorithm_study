// 부녀회장이 될테야
#include <iostream>
using namespace std;

int t, k, n;
int DP[15][15];

int main() {
    cin >> t;
    for (int i = 0; i <= 14; i++) {
        DP[i][1] = 1;
        DP[0][i] = i;
    }
    for (int i = 1; i <= t; i++) {
        cin >> k >> n;
        for (int f = 1; f <= k; f++) {
            for (int m = 2; m <= n; m++) {
                DP[f][m] = DP[f - 1][m] + DP[f][m - 1];
            }
        }
        cout << DP[k][n] << '\n';
    }
}