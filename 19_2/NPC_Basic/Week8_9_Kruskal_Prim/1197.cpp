// 최소 스패닝 트리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DisjointSet
{
    vector<int> par;
    DisjointSet(int a)
    {
        par.resize(a + 5, -1);
    }
    int f(int v)
    {
        if (par[v] == -1) return v;
        return par[v] = f(par[v]);
    }
    void u(int x, int y)
    {
        x = f(x), y = f(y);
        if (x == y) return;
        par[x] = y;
    }
};

struct edge
{
    int A, B, C;
};
edge edges[100001];

bool cmp(const edge& e1, const edge& e2)
{
    return e1.C < e2.C;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;
    for (int i = 1 ; i <= E; i++)
        cin >> edges[i].A >> edges[i].B >> edges[i].C;
    sort(edges + 1, edges + E + 1, cmp);
    DisjointSet ds(V);
    int ans = 0;
    int cnt = 1, idx = 1;
    while (cnt < V)
    { 
        if (ds.f(edges[idx].A) != ds.f(edges[idx].B))
        {
            ds.u(edges[idx].A, edges[idx].B);
            ans += edges[idx].C;
            cnt++;
        }
        idx++;
    }
    cout << ans;
    return 0;
}