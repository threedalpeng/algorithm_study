#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet {
    vector<int> par;
    DisjointSet(int a) {
        par.resize(a + 5, -1);
    }

    int f(int v) {
        if (par[v] == -1) return v;
        return par[v] = f(par[v]);
    }

    void u(int x, int y) {
        x = f(x), y = f(y);
        if (x == y) return;
        par[x] = y;
    }

    void print() {
        for (int i = 1; i <= par.size() - 5; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        for (int i = 1; i <= par.size() - 5; i++) {
            cout << (par[i] == -1 ? 0 : par[i]) << ' ';
        }
        cout << "\n\n";
    }
};

int main() {
    DisjointSet ds(7);
    ds.print();
    ds.u(1, 5);
    ds.print();
    ds.u(4, 7);
    ds.print();
    ds.u(4, 6);
    ds.print();
    ds.u(4, 5);
    ds.print();
}