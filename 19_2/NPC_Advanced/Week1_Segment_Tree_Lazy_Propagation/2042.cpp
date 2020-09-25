// 구간 합 구하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long int;

struct SegTree
{
    int base;
    vector<ll> tree;
    
    SegTree(int n)
    {
        base = 1;
        while (base < n) base <<= 1;
        tree.resize(base * 2 + 2);
        --base;
    }

    void update(int idx, ll val)
    {
        idx += base;
        tree[idx] = val;
        idx >>= 1;
        while (idx != 0)
        {
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1]; // expr
            idx >>= 1;
        }
    }
    
    ll query(int st, int fn, int ns = 1, int nf = -1, int num = 1)
    {
        if (nf == -1) nf = base + 1;
        if (ns > fn || nf < st) return 0;
        if (st <= ns && nf <= fn) return tree[num];
        int mid = (ns + nf) >> 1;
        return query(st, fn, ns, mid, num * 2) + query(st, fn, mid + 1, nf, num * 2 + 1); // expr
    }
};

int n, m, k;
ll a, b, c;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    SegTree stree(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        stree.update(i, a);
    }
    for (int i = 1; i <= m + k; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            stree.update(b, c);
        }
        else if (a == 2)
        {
            cout << stree.query(b, c) << '\n';
        }
    }
}