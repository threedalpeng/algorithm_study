#include <algorithm>
#include <iostream>
using namespace std;

int N, w;
struct Candy {
    int t, s;
};
Candy c[250001];

bool cmp(Candy c1, Candy c2) {
    return c1.s > c2.s;
}

bool pos(int mid) {
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> w;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> c[i].t >> c[i].s;
        sum += c[i].s;
    }
    sort(c, c + N, cmp);
    int first = 0, last = sum, mid;
    while (first <= last) {
        mid = (first + last) >> 1;
        if (pos(mid)) last = mid - 1;
        else
            first = mid + 1;
    }
}