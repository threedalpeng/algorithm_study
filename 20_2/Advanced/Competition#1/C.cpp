#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 1e9;

int N, K, M, J;
int bin[100'001];
map<int, int> b_idx;
vector<int> graph[100'001];
int dist[100'001], path[100'001];
bool check[100'001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int bin_num;
    cin >> N >> K;

    string bin_str;
    for (int i = 1; i <= N; i++) {
        cin >> bin_str;
        bin[i] = 0;
        for (int j = 0; j < K; j++) {
            bin[i] <<= 1;
            bin[i] |= (bin_str[j] - '0');
        }
        b_idx[bin[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < K; j++) {
            auto idx = b_idx.find(bin[i] ^ (1 << j));
            if (idx != b_idx.end()) {
                graph[i].push_back(idx->second);
            }
        }
    }

    int v, d;
    for (int i = 1; i <= N; i++) {
        check[i] = false;
        dist[i] = INF;
        path[i] = -1;
    }
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({ dist[1], 1 });
    while (!PQ.empty()) {
        do {
            v = PQ.top().second;
            PQ.pop();
        } while (!PQ.empty() && check[v]);

        if (!check[v])
            check[v] = true;
        else
            break;

        for (int j = 0; j < graph[v].size(); j++) {
            int nxt = graph[v][j];
            if (!check[nxt] && dist[nxt] > dist[v] + 1) {
                dist[nxt] = dist[v] + 1;
                path[nxt] = v;
                PQ.push({ dist[nxt], nxt });
            }
        }
    }

    cin >> M;
    while (M--) {
        cin >> J;
        if (path[J] == -1) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> answer;
        while (J != 1) {
            answer.push_back(J);
            J = path[J];
        }
        answer.push_back(1);
        for (auto it = answer.crbegin(); it < answer.crend(); it++) {
            cout << (*it) << ' ';
        }
        cout << '\n';
    }
}