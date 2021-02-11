// 동전 0
#include <iostream>
using namespace std;

int N, K, A[10];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int cnt = 0, i = N - 1;
    while (K && i >= 0) {
        cnt += (K / A[i]);
        K %= A[i];
        --i;
    }
    cout << cnt;
}