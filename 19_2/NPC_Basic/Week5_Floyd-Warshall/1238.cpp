// 파티
#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1e9;
int DP[1001][1001];
int n, m, x, s, f, t;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> x;

    // initializing
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j) DP[i][j] = 0;
            else
                DP[i][j] = INF;
        }

    for (int i = 1; i <= m; i++) {
        cin >> s >> f >> t;
        DP[s][f] = t;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);

    int Mx = 0;
    for (int i = 1; i <= n; i++) {
        if (x != i)
            Mx = max(Mx, DP[i][x] + DP[x][i]);
    }

    cout << Mx;
}