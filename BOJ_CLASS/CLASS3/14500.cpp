// 테트로미노
#include <iostream>
using namespace std;

int N, M;
int grid[500][500];
bool check[500][500];

int bf(int x, int y, int sum, int depth = 0) {
    if (depth == 3) {
        return sum;
    }

    int sub, result = 0;
    int cx = x - 1, cy = y;
    if (cx >= 0 && !check[cx][cy]) {
        check[cx][cy] = true;
        sub = bf(cx, cy, sum + grid[cx][cy], depth + 1);
        result = max(result, sub);
        check[cx][cy] = false;
    }
    cx = x, cy = y - 1;
    if (cy >= 0 && !check[cx][cy]) {
        check[cx][cy] = true;
        sub = bf(cx, cy, sum + grid[cx][cy], depth + 1);
        result = max(result, sub);
        check[cx][cy] = false;
    }
    cx = x + 1, cy = y;
    if (cx < N && !check[cx][cy]) {
        check[cx][cy] = true;
        sub = bf(cx, cy, sum + grid[cx][cy], depth + 1);
        result = max(result, sub);
        check[cx][cy] = false;
    }
    cx = x, cy = y + 1;
    if (cy < M && !check[cx][cy]) {
        check[cx][cy] = true;
        sub = bf(cx, cy, sum + grid[cx][cy], depth + 1);
        result = max(result, sub);
        check[cx][cy] = false;
    }

    return result;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            check[i][j] = true;
            mx = max(mx, bf(i, j, grid[i][j]));
            check[i][j] = false;
            // cout << mx << '\n';
        }
    }

    int sub = 0;
    for (int i = 1; i < N - 1; i++) {
        mx = max(mx, max(grid[i][0] + grid[i - 1][0] + grid[i + 1][0] + grid[i][1], grid[i][M - 1] + grid[i - 1][M - 1] + grid[i + 1][M - 1] + grid[i][M - 2]));
    }
    for (int i = 1; i < M - 1; i++) {
        mx = max(mx, max(grid[0][i] + grid[0][i - 1] + grid[0][i + 1] + grid[1][i], grid[N - 1][i] + grid[N - 1][i - 1] + grid[N - 1][i + 1] + grid[N - 2][i]));
    }
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            sub = grid[i][j] + grid[i - 1][j] + grid[i][j - 1] + grid[i + 1][j] + grid[i][j + 1];
            mx = max(mx, max(max(sub - grid[i - 1][j], sub - grid[i][j - 1]), max(sub - grid[i + 1][j], sub - grid[i][j + 1])));
        }
    }

    cout << mx << '\n';
}