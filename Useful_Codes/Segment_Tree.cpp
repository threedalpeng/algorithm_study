// Segment Tree
#include <algorithm>
#include <vector>
using namespace std;

// Segment Tree
struct SegTree {
    // tree
    vector<int> tree;

    // constructor making a tree
    int base;
    SegTree(int a) {
        base = 1;
        while (base < a)
            base <<= 1;
        tree.resize(base * 2 + 2);
        --base;
    }

    // updating a value of the 'idx' of the tree to 'val';
    void update(int idx, int val) {
        idx += base;
        tree[idx] = val;
        idx >>= 1;
        while (idx != 0) {
            tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]); // expr
            idx >>= 1;
        }
    }

    // get the result from 'st' to 'fn'
    int query(int st, int fn, int ns = 1, int nf = -1, int num = 1) {
        if (nf == -1)
            nf = base + 1;
        if (nf < st || ns > fn)
            return 0;
        if (st <= ns && nf <= fn)
            return tree[num];
        int mid = (ns + nf) >> 1;
        return max(query(st, fn, ns, mid, num * 2), query(st, fn, mid + 1, nf, num * 2 + 1)); // expr
    }
};