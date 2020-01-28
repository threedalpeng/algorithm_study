// 거의 최단 경로
#include <iostream>
#include <list>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
using P = pair<int, int>;
using PQ = priority_queue<P, vector<P>, greater<P>>;

const int INF = 1e9;
int n, m, s, d, u, v, p, cur, mn;
list<P> lst[500];
int dist[500];
vector<int> path[500];
bool check[500];

void init(int v)
{
    memset(check, false, n * sizeof(bool));
    for (int i = 0; i < n; i++)
    {   
        dist[i] = INF;
        path[i].clear();
    }
    dist[v] = 0;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    while( !(n == 0 && m == 0) )
    {
        mn = -1;
        cin >> s >> d;
        init(s);
        for (int i = 0; i < n; i++)
            lst[i].clear();
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> p;
            lst[u].push_back(P(p, v));
        }
        
        while(true)
        {
            PQ pq;
            init(s);
            pq.push(P(dist[s], s));
            while(!pq.empty())
            {
                do
                {
                    cur = pq.top().second;
                    pq.pop();
                } while (!pq.empty() && check[cur]);
                
                if (!check[cur]) check[cur] = true;
                else break;

                for (auto x : lst[cur])
                {
                    int w = x.first;
                    int nxt = x.second;
                    if (!check[nxt] && dist[nxt] >= dist[cur] + w)
                    {
                        if (dist[nxt] > dist[cur] + w) path[nxt].clear();
                        path[nxt].push_back(cur);
                        dist[nxt] = dist[cur] + w;
                        pq.push(P(dist[nxt], nxt));
                    }
                }
            }

            // cout << "cur min: " << dist[d] << '\n';
            if (dist[d] == INF)
            {
                cout << -1 << '\n';
                break;
            }

            if (mn == -1) // 1st try
            {
                mn = dist[d];
            }
            else if (mn < dist[d])
            {
                cout << dist[d] << '\n';
                break;
            }
            
            cur = d;
            queue<P> btrack;
            for (int i = 0; i < path[cur].size(); i++)
            {
                btrack.push({cur, path[cur][i]});
            }
            while(!btrack.empty())
            {
                P trace = btrack.front();
                btrack.pop();
                lst[trace.second].remove_if([trace](P p)->bool{ return p.second == trace.first; });
                
                for (int i = 0; i < path[trace.second].size(); i++)
                {
                    btrack.push({trace.second, path[trace.second][i]});
                }
            }
        }
        cin >> n >> m;
    }
}