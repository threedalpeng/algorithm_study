// DFS와 BFS
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> list[1002];
bool check[1002];

void DFS(int v) {
    cout << v << ' ';
    check[v] = true;
    for (int i = 0; i < list[v].size(); i++)
        if (!check[list[v][i]])
            DFS(list[v][i]);
}

void BFS(int v) {
    memset(check, false, sizeof(check));
    q.push(v);
    check[v] = true;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << ' ';
        for (int i = 0; i < list[v].size(); i++) {
            if (!check[list[v][i]]) {
                q.push(list[v][i]);
                check[list[v][i]] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, V, from, to;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        list[from].push_back(to);
        list[to].push_back(from);
    }
    for (int i = 1; i <= N; i++)
        sort(list[i].begin(), list[i].end());
    DFS(V);
    cout << '\n';
    BFS(V);
}