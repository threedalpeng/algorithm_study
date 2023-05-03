// 트리의 지름
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int V;
vector<pii> tree[100'001];

pii dfs(int st) {
    stack<pii> S;
    vector<int> visited(V + 1);

    int pt = -1;
    int max_dist = 0;

    S.push({ st, 0 });
    for (int i = 0; i <= st; i++) {
        visited[st] = true;
    }

    while (!S.empty()) {
        pii np = S.top();
        int vt = np.first;
        int vd = np.second;
        S.pop();

        bool is_endpoint = true;
        for (auto p : tree[vt]) {
            int nvt = p.first;
            int dist = p.second;
            if (!visited[nvt]) {
                is_endpoint = false;
                visited[nvt] = true;
                S.push({ nvt, vd + dist });
            }
        }

        if (is_endpoint) {
            if (max_dist < vd) {
                max_dist = vd;
                pt = vt;
            }
        }
    }

    return make_pair(pt, max_dist);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> V;
    int next, d, r;
    for (int i = 1; i <= V; i++) {
        cin >> r;
        while (cin >> next && next != -1) {
            cin >> d;
            tree[r].push_back({ next, d });
        }
    }

    pii farthestFromOne = dfs(1);
    int end = farthestFromOne.first;
    pii diameter = dfs(end);
    cout << diameter.second << '\n';
}