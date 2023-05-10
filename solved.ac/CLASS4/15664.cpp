// N과 M (10)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int N, M;
int a[9];
vector<int> s;

int replaceTop(int cur) {
    if (s.back() == a[cur]) {
        return -1;
    }
    s.pop_back();
    s.push_back(a[cur]);
    return 1;
}
void next(int cur, int depth) {
    if (cur >= N) {
        return;
    }

    if (replaceTop(cur) == -1) {
        return;
    }

    if (depth == 1) {
        for (int i = 0; i < M; i++) {
            cout << s[i] << ' ';
        }
        cout << '\n';
        return;
    }

    s.push_back(-1);
    for (int i = cur + 1; i < N; i++)
        next(i, depth - 1);

    s.pop_back();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);

    s.push_back(-1);
    for (int i = 0; i < N; i++)
        next(i, M);
    s.pop_back();
}