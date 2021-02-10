// 경로 찾기
#include <algorithm>
#include <iostream>
using namespace std;

int graph[101][101], N;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> graph[i][j];

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cout << graph[i][j] << ' ';
        cout << '\n';
    }
}