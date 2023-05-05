// 특정한 최단 경로
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
using p = pair<int, int>;
const int INF = 1e8;

int N, E;
vector<p> graph[1001];
int dist[801], path[801];
bool check[1001];

void init(int v) {
    memset(check, false, (N + 1) * sizeof(bool));
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        path[i] = -1;
    }
    dist[v] = 0;
}

void dijkstra(int v) {
    init(v);
    priority_queue<p, vector<p>, greater<p>> PQ;
    PQ.push({ dist[v], v });
    while (!PQ.empty()) {
        do {
            v = PQ.top().second;
            PQ.pop();
        } while (!PQ.empty() && check[v]);

        if (!check[v])
            check[v] = true;
        else
            break;

        for (int j = 0; j < graph[v].size(); j++) {
            int w = graph[v][j].first;
            int nxt = graph[v][j].second;
            if (!check[nxt] && dist[nxt] > dist[v] + w) {
                dist[nxt] = dist[v] + w;
                path[nxt] = v;
                PQ.push({ dist[nxt], nxt });
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> E;

    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });
    }

    int v1, v2;
    cin >> v1 >> v2;

    int sum = 0;
    dijkstra(1);
    int _1_v1 = dist[v1];
    int _1_v2 = dist[v2];
    dijkstra(v1);
    int _v1_v2 = dist[v2];
    int _v1_N = dist[N];
    dijkstra(v2);
    int _v2_N = dist[N];

    int result = min(_1_v1 + _v1_v2 + _v2_N, _1_v2 + _v1_v2 + _v1_N);
    cout << (result >= INF ? -1 : result) << '\n';
}