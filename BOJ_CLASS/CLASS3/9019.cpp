#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pis = pair<int, string>;

const int nNode = 10'000;

int T, A, B;
vector<int> graph[nNode];
bool check[nNode];

void init() {
    memset(check, false, 10000);
}

string bfs() {
    queue<pis> Q;
    Q.push({ A, "" });
    check[A] = true;
    int d1, d2, d3, d4;
    while (!Q.empty()) {
        pis src = Q.front();
        Q.pop();
        if (src.first == B)
            return src.second;

        d1 = graph[src.first][0];
        d2 = graph[src.first][1];
        d3 = graph[src.first][2];
        d4 = graph[src.first][3];
        if (!check[d1]) {
            check[d1] = true;
            Q.push({ d1, src.second + "D" });
        }
        if (!check[d2]) {
            check[d2] = true;
            Q.push({ d2, src.second + "S" });
        }
        if (!check[d3]) {
            check[d3] = true;
            Q.push({ d3, src.second + "L" });
        }
        if (!check[d4]) {
            check[d4] = true;
            Q.push({ d4, src.second + "R" });
        }
    }
    return "";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    for (int i = 0; i < nNode; i++) {
        graph[i].push_back((2 * i) % 10000);
        graph[i].push_back((i + 9999) % 10000);
        graph[i].push_back((i * 10 + i / 1000) % 10000);
        graph[i].push_back((i % 10) * 1000 + i / 10);
    }

    for (int i = 0; i < T; i++) {
        init();
        cin >> A >> B;
        cout << bfs() << '\n';
    }
}