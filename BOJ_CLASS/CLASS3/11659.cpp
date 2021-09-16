// 구간 합 구하기 4
#include <iostream>
using namespace std;

int N, M;
int a[100'001] = { 0 };
int s, e;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        cout << a[e] - a[s - 1] << '\n';
    }
}