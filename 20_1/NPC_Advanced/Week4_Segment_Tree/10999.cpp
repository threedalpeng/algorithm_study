#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct SegTree
{
    vector<int> tree, lazy;

    int base;
    SegTree(int a)
    {
        base = 1;
        while(base < a) base <<= 1;
        tree.resize(base * 2 + 2);
        lazy.resize(base * 2 + 2);
        --base;
    }
}

void propagate(int ns, int nf, int num)
{
    if (lazy[num] != 0)
    {
        if (ns < nf)
        {
            lazy[num * 2] += lazy[num];
            lazyp
        }
    }
}

int main()
{

}