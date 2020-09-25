#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SegTree
{
    vector<int> tree;

    int base;
    SegTree(int n)
    {
        base = 1;
        while(base < n) base <<= 1;
        tree.resize(base * 2 + 2);
        --base;
    }

    void update(int idx, int val)
    {
        idx += base;
        tree[idx] = val;
        idx >>= 1;
        while(idx != 0)
        {
            tree[]
        }
    }
}