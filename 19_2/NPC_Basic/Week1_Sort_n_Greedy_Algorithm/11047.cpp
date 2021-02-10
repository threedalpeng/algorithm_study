// 동전 0
#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int nCoin = 0;
    for (int i = N - 1; i >= 0; i--) {
        nCoin += K / A[i];
        K -= (K / A[i]) * A[i];
    }

    cout << nCoin;
}