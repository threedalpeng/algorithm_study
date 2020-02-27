// 여행 가자
#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet
{
    vector<int> v;
    DisjointSet(int n)
    {
        v.resize(n + 5, -1);
    }
    int f(int n)
    {
        if (v[n] == -1) return n;
        return v[n] = f(v[n]);
    }
    void u(int a, int b)
    {
        a = f(a), b = f(b);
        if (a == b) return;
        v[a] = b;
    }
};

int n, m, a, b;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    DisjointSet ds(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            if (a) ds.u(i, j);
        }
    }

    cin >> a;
    int start_set = ds.f(a);
    bool avail = true;
    for (int i = 1; i < m; i++)
    {
        cin >> a;
        if (start_set != ds.f(a))
        {
            avail = false;
            break;
        }
    }
    if (avail) cout << "YES";
    else cout << "NO";
}