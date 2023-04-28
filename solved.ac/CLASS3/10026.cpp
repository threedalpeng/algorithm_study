// 적록색약
#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N, cntCommon, cntColorWeak;
string pic[100];
bool check[100][100];

void bfsCommon(int x, int y) {
    if (check[x][y])
        return;
    cntCommon++;
    check[x][y] = true;
    char c = pic[x][y];
    queue<pii> Q;
    Q.push({ x, y });
    while (!Q.empty()) {
        pii pt = Q.front();
        Q.pop();
        int px = pt.first;
        int py = pt.second;
        if (px >= 1 && !check[px - 1][py] && pic[px - 1][py] == c) {
            check[px - 1][py] = true;
            Q.push({ px - 1, py });
        }
        if (py >= 1 && !check[px][py - 1] && pic[px][py - 1] == c) {
            check[px][py - 1] = true;
            Q.push({ px, py - 1 });
        }
        if (px < N - 1 && !check[px + 1][py] && pic[px + 1][py] == c) {
            check[px + 1][py] = true;
            Q.push({ px + 1, py });
        }
        if (py < N - 1 && !check[px][py + 1] && pic[px][py + 1] == c) {
            check[px][py + 1] = true;
            Q.push({ px, py + 1 });
        }
    }
}

void bfsColorWeak(int x, int y) {
    if (check[x][y])
        return;
    cntColorWeak++;
    check[x][y] = true;
    char c = pic[x][y];
    queue<pii> Q;
    Q.push({ x, y });
    while (!Q.empty()) {
        pii pt = Q.front();
        Q.pop();
        int px = pt.first;
        int py = pt.second;
        if (px >= 1 && !check[px - 1][py] && pic[px - 1][py] == c) {
            check[px - 1][py] = true;
            Q.push({ px - 1, py });
        }
        if (py >= 1 && !check[px][py - 1] && pic[px][py - 1] == c) {
            check[px][py - 1] = true;
            Q.push({ px, py - 1 });
        }
        if (px < N - 1 && !check[px + 1][py] && pic[px + 1][py] == c) {
            check[px + 1][py] = true;
            Q.push({ px + 1, py });
        }
        if (py < N - 1 && !check[px][py + 1] && pic[px][py + 1] == c) {
            check[px][py + 1] = true;
            Q.push({ px, py + 1 });
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pic[i];
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            bfsCommon(i, j);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            check[i][j] = false;
            if (pic[i][j] == 'G')
                pic[i][j] = 'R';
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            bfsColorWeak(i, j);

    cout << cntCommon << ' ' << cntColorWeak << '\n';
}