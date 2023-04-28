// 거짓말
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
};

int N, M, k, r, a;
vector<vector<int>> v;

int main() {
    cin >> N >> M;
    cin >> k;
    DisjointSet ds(51);

    for (int i = 0; i < k; i++) {
        cin >> a;
        ds.u(0, a);
    }

    v.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> a;
        v[i].resize(a);
        for (int j = 0; j < a; j++) {
            cin >> v[i][j];
            ds.u(v[i][0], v[i][j]);
        }
    }

    int cnt = 0;
    for (auto vf : v) {
        bool knows = false;
        for (auto i : vf) {
            if (ds.f(0) == ds.f(i)) {
                knows = true;
                break;
            }
        }
        if (!knows) {
            cnt++;
        }
    }

    cout << cnt << '\n';
}