#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet {
    vector<int> par;
    DisjointSet(int n) {
        par.resize(n + 1, -1);
    }

    int f(int v) {
        if (par[v] == -1) return v;
        else
            return v = par[v];
    }

    void u(int a, int b) {
        a = f(a), b = f(b);
        if (a == b) return;
        par[a] = b;
    }
};

int N, M;
int x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
}