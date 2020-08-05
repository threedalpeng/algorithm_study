// 연결 요소의 개수
#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet
{
    vector<int> par;
    DisjointSet(int n)
    {
        par.resize(n + 1, -1);
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
        par[y] = x;
    }
};
int N, M, u, v;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    DisjointSet ds(N);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        ds.u(u, v);
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (ds.par[i] == -1) cnt++;
    }
    cout << cnt;
}