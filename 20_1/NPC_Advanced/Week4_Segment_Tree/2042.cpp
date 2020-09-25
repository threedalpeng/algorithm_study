// 구간 합 구하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct SegTree
{
    vector<ll> tree;

    int base;
    SegTree(int n)
    {
        base = 1;
        while(base < n) base <<= 1;
        tree.resize(base * 2 + 2);
        --base;
    }

    void update(int idx, ll val)
    {
        idx += base;
        tree[idx] = val;
        idx >>= 1;
        while(idx != 0)
        {
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
            idx >>= 1;
        }
    }

    ll query(int st, int fn, int ns = 1, int nf = -1, int num = 1)
    {
        if (nf == -1) nf = base + 1;
        if (nf < st || ns > fn) return 0;
        if (st <= ns && nf <= fn) return tree[num];
        int mid = (ns + nf) >> 1;
        return query(st, fn, ns, mid, num * 2) + query(st, fn, mid + 1, nf, num * 2 + 1);
    }
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, K;
    ll a, b, c, num;
    cin >> N >> M >> K;
    SegTree stree(N);
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        stree.update(i, num);
    }
    for (int i = 1; i <= M + K; i++)
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