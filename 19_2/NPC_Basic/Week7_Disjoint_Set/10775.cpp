// 공항
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
        x = f(x); y = f(y);
        if (x == y) return;
        par[x] = y;
    }
};

int g, p, gi;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> g;
    cin >> p;
    DisjointSet ds(g);
    int cnt = 0;
    for (int i = 1; i <= p; i++)
    {
        cin >> gi;
        if (ds.f(gi) == 0) 
        {
            break;
        }
        else
        {
            ds.u(gi, ds.f(gi) - 1);
            cnt++;
        }
    }
    cout << cnt;
}