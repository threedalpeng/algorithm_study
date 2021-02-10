// 등산
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using Pii = pair<int, int>;
const int INF = 1e9;

struct C {
    int x, y;
};

int n, m, t, d;
int map[25][25];
vector<Pii> graph[25 * 25 + 1];
C drt[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int dist[626];
bool check[626];
int res[626];

int ctoi(char c) {
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    else if ('a' <= c && c <= 'z')
        return c - 'a' + 26;
    else
        return -1;
}
int time(C from, C to) {
    int fh = map[from.x][from.y];
    int th = map[to.x][to.y];
    if (abs(fh - th) > t) return INF;
    if (fh >= th) return 1;
    else
        return (th - fh) * (th - fh);
}
bool avail(C p) { return (0 <= p.x && p.x < n && 0 <= p.y && p.y < m); }
int mtog(C p) { return p.x * m + p.y; }
C gtom(int i) { return { i / m, i % m }; }

void init() {
    memset(check, false, n * m * sizeof(bool));
    for (int i = 0; i < n * m; i++) {
        graph[i].clear();
        dist[i] = INF;
    }
    dist[0] = 0;
}

void dijkstra() {
    priority_queue<Pii, vector<Pii>, greater<Pii>> pq;
    pq.push({ 0, 0 });
    while (!pq.empty()) {
        int cur;
        do {
            cur = pq.top().second;
            pq.pop();
        } while (!pq.empty() && check[cur]);

        if (!check[cur]) check[cur] = true;
        else
            break;

        for (int i = 0; i < graph[cur].size(); i++) {
            int w = graph[cur][i].first;
            int nxt = graph[cur][i].second;
            if (!check[nxt] && dist[nxt] > dist[cur] + w) {
                dist[nxt] = dist[cur] + w;
                pq.push({ dist[nxt], nxt });
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string lines;
    cin >> n >> m >> t >> d;
    for (int i = 0; i < n; i++) {
        cin >> lines;
        for (int j = 0; j < m; j++) {
            map[i][j] = ctoi(lines[j]);
        }
    }

    init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C cur = { i, j };
            for (int k = 0; k < 4; k++) {
                C nxt = { cur.x + drt[k].x, cur.y + drt[k].y };
                if (avail(nxt)) {
                    graph[mtog({ i, j })].push_back({ time(cur, nxt), mtog(nxt) });
                }
            }
        }
    }
    dijkstra();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << dist[mtog({i, j})] << ' ';
            res[mtog({ i, j })] = dist[mtog({ i, j })];
        }
        // cout << '\n';
    }

    init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C cur = { i, j };
            for (int k = 0; k < 4; k++) {
                C nxt = { cur.x + drt[k].x, cur.y + drt[k].y };
                if (avail(nxt)) {
                    graph[mtog({ i, j })].push_back({ time(nxt, cur), mtog(nxt) });
                }
            }
        }
    }
    dijkstra();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << dist[mtog({i, j})] << ' ';
            res[mtog({ i, j })] += dist[mtog({ i, j })];
        }
        // cout << '\n';
    }

    int max_height = 0;
    C top_coor;
    for (int i = 0; i < n * m; i++) {
        if (res[i] <= d) {
            C mc = gtom(i);
            if (max_height < map[mc.x][mc.y]) {
                max_height = map[mc.x][mc.y];
            }
        }
    }

    cout << max_height;
}