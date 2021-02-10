// 저울
#include <iostream>
using namespace std;

int D[101][101];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        if (D[a][b] == 0) D[a][b] = 1, D[b][a] = -1;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (D[i][j] == 0 && i != j) {
                    if (D[i][k] == 1 && D[k][j] == 1) D[i][j] = 1, D[j][i] = -1;
                    else if (D[i][k] == -1 && D[k][j] == -1)
                        D[i][j] = -1, D[j][i] = 1;
                }

    int cnt;
    for (int i = 1; i <= N; i++) {
        cnt = -1;
        for (int j = 1; j <= N; j++)
            if (D[i][j] == 0) ++cnt;
        cout << cnt << '\n';
    }
}