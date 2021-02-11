// 토마토
#include <iostream>
#include <queue>
using namespace std;

int M, N, H, box[100][100][100];
struct P {
    int x, y, z;
    P(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}
    P operator+(const P& p) { return { x + p.x, y + p.y, z + p.z }; }
    bool operator==(const P& p) { return (x == p.x && y == p.y && z == p.z); }
    bool isInside() { return 0 <= x && x < M && 0 <= y && y < N && 0 <= z && z < H; }
};
P drt[6] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    queue<P> q;
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                    q.push(P(k, j, i));
            }

    int res = 0;
    P cur, next;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            cur = q.front();
            q.pop();
            for (int j = 0; j < 6; j++) {
                next = cur + drt[j];
                if (next.isInside() && box[next.z][next.y][next.x] == 0) {
                    box[next.z][next.y][next.x] = 1;
                    q.push(next);
                }
            }
        }
        ++res;
    }
    --res;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++)
                if (box[i][j][k] == 0) {
                    res = -1;
                    break;
                }
            if (res == -1) break;
        }
        if (res == -1) break;
    }
    cout << res << '\n';
}