// 2×n 타일링
#include <iostream>
using namespace std;

int main() {
    int n, DP[1'001];
    cin >> n;
    DP[0] = 1;
    DP[1] = 1;
    for (int i = 2; i <= n; i++) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
    }
    cout << DP[n];
}