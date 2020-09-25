// 파티
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using p = pair<int, int>;
const int INF = 1e9;

int n, m, x, s, f, t;
vector<p> lst[1001];
int dist[1001], path[1001];
bool check[1001];

void init(int v)
{
    memset(check, false, (n + 1) * sizeof(path));
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        path[i] = -1;
    }
    dist[v] = 0;
}

int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++)
    {
        cin >> s >> f >> t;
        lst[s].push_back({t, f});
    }

    int v, d;
    for (int i = 1; i <= n; i++)
    {
        init(i);
        priority_queue<p, vector<p>, greater<p>> PQ;
        PQ.push({dist[i], i});
        while(!PQ.empty())
        {
            // 1. v 찾기
            do {
                v = PQ.top().second;
                PQ.pop();
            } while (!PQ.empty() && check[v]);
            
            // 2. check[v] = true;
            if (!check[v]) check[v] = true;
            else break;

            // 3. update
            for (int j = 0; j < lst[v].size(); i++)
            {
                int w = lst[v][j].first;
                int nxt = lst[v][j].second;
                if (!check[nxt] && dist[nxt] > dist[v] + w)
                {
                    dist[nxt] = dist[v] + w;
                    path[nxt] = v;
                    PQ.push({dist[nxt], nxt});
                }
            }
        }
    }
}