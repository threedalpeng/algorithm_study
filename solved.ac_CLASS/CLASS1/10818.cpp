// 최소, 최대
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, num, mn = 1e6, Mx = -1e6;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        mn = min(num, mn);
        Mx = max(num, Mx);
    }
    cout << mn << ' ' << Mx;
}