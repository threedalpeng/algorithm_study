// Segment Tree with Lazy Propagation
#include <vector>
#include <algorithm>
using namespace std;

// Segment Tree
struct SegTree
{
    // segment tree and tree for lazy propagation
    vector<int> tree, lazy;

    // constructor making a tree
    int base;
    SegTree(int a)
    {
        base = 1;
        while (base < a)
            base <<= 1;
        tree.resize(base * 2 + 2);
        lazy.resize(base * 2 + 2);
        --base;
    }

    // performing a propagation operation
    void propagate(int ns, int nf, int num)
    {
        if (lazy[num] != 0)
        {
            if (ns < nf)
            {
                lazy[num * 2] += lazy[num];
                lazy[num * 2 + 1] += lazy[num];
            }
            tree[num] += lazy[num] * (nf - ns + 1);
            lazy[num] = 0;
        }
    }

    // updating a value of the 'idx' of the tree to 'val'
    void update(int idx, int val)
    {
        idx += base;
        tree[idx] = val;
        idx >>= 1;
        while (idx != 0)
        {
            tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
            idx >>= 1;
        }
    }

    // get the result from 'st' to 'fn'
    int query(int st, int fn, int ns = 1, int nf = -1, int num = 1)
    {
        if (nf == -1)
            nf = base + 1;
        propagate(ns, nf, num);
        if (nf < st || ns > fn)
            return 0;
        if (st <= ns && nf <= fn)
            return tree[num];
        int mid = (ns + nf) >> 1;
        return max(query(st, fn, ns, mid, num * 2), query(st, fn, mid + 1, nf, num * 2 + 1));
    }

    // updating the segment from st to fn
    void add_value(int val, int st, int fn, int ns = 1, int nf = -1, int num = 1)
    {
        if (nf == -1)
            nf = base + 1;
        propagate(ns, nf, num);
        if (ns > fn || nf < st)
            return;
        if (st <= ns && nf <= fn)
        {
            lazy[num] += val;
            propagate(ns, nf, num);
            return;
        }
        int mid = (ns + nf) >> 1;
        add_value(val, st, fn, ns, mid, num * 2);
        add_value(val, st, fn, mid + 1, nf, num * 2 + 1);
        tree[num] = tree[num * 2] + tree[num * 2 + 1];
    }
};
