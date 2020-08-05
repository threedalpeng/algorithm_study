#include <iostream>
#include <vector>
using namespace std;

int n, q, a, x, b, c, d;
int link[200001];
vector<pair<int, int>> quest;
vector<bool> ans;

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
        par[x] = y;
    }
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> q;
    DisjointSet ds(n);
    for (int i = 2; i <= n; i++)
    {
        cin >> link[i];
    }
    for (int i = 1; i <= n - 1 + q; i++)
    {
        cin >> x;
        if (x)
        {
            cin >> c >> d;
            quest.push_back(make_pair(c, d));
        }
        else
        {
            cin >> b;
            quest.push_back(make_pair(0, b));
        }
    }
    for (auto i = quest.rbegin(); i != quest.rend(); i++)
    {
        int f = (*i).first;
        int s = (*i).second;
        if (f)
        {
            if (ds.f(f) == ds.f(s))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        else
        {
            ds.u(s, link[s]);
        }
    }
    for (auto i = ans.rbegin(); i != ans.rend(); i++)
    {
        if(*i) cout << "YES\n";
        else cout << "NO\n";
    }
}