// 집합의 표현
#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet
{
    vector<int> par;
    DisjointSet(int a)
    {
        par.resize(a+5, -1);
    }
    int f(int v)
    {
        if (par[v] == -1) return v;
        return par[v] = f(par[v]); // path compression
    }
    void u(int x, int y)
    {
        x = f(x), y = f(y);
        // already in a same set
        if (x == y) return;
        par[x] = y;
    }
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, s, a, b;
    cin >> n >> m;
    DisjointSet ds(n);
    for (int i = 0; i < m; i++)
    {
        cin >> s >> a >> b;
        if (s) // find
        {
            if (ds.f(a) == ds.f(b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else // union
        {
            ds.u(a, b);
        }
    }
}