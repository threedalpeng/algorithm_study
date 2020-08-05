// 최단 경로
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// first: next vertex, second: dist
typedef pair<int, int> P; 

int V, E, K;
vector<pair<int, int>> list[20001];
int dist[20001], path[20001];
bool check[20001];
const int INF = 2e9;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int u, v, w;
    priority_queue<P, vector<P>, greater<P>> PQ; // first: dist, second: next vertex

    // 초기화
    cin >> V >> E; // 정점, 간선 개수
    cin >> K; // 시작점

    for (int i = 1; i <= V; i++) dist[i] = INF, path[i] = -1;
    dist[K] = 0;
    
    // 그래프 생성
    for (int i = 1; i <= E; i++)
    {
        cin >> u >> v >> w;
        list[u].push_back(P(v, w));
    }

    PQ.push(P(0, K));
    while(!PQ.empty())
    {
        // 1. vtx 구하기
        int vtx;
        do
        {
            vtx = PQ.top().second; // dist가 최소인 정점
            PQ.pop();
        } while (!PQ.empty() && check[vtx]); // check가 false일때 break
        if (check[vtx]) break;

        // 2. check[vtx]
        check[vtx] = true;

        // 3. 인접한 정점 갱신
        for (int i = 0; i < list[vtx].size(); i++)
        {
            int next = list[vtx][i].first;
            int d = list[vtx][i].second;
            if (!check[next] && dist[next] > dist[vtx] + d)
            {
                dist[next] = dist[vtx] + d;
                PQ.push(P(dist[next], next));
                path[next] = vtx;
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}