#include <bits/stdc++.h>
using namespace std;

int N, M, x, y;
int a[10'000];

struct DisjointSet {
    vector<int> par;
    DisjointSet(int a) {
        par.resize(a + 1, -1);
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    DisjointSet ds(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i =0; i < M; i++) {
        cin >> x >> y;
        ds.u(x, y);
    }

    for (int i = 0; i < N; i++) {
        if (i != ds.f(i)) {
            a[ds.f(i)] += a[i];
            a[i] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        if (a[i] != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << "POSSIBLE\n";
}