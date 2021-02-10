// 좌표 정렬하기 2
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct C {
    int x, y;
};
int n;
C c[100001];

bool cmp(C c1, C c2) {
    if (c1.y == c2.y) return c1.x < c2.x;
    return c1.y < c2.y;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].x >> c[i].y;
    }
    stable_sort(c + 1, c + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << c[i].x << ' ' << c[i].y << '\n';
    }
}