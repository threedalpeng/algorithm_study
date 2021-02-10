#include <iostream>
using namespace std;
typedef long long ll;
const ll divi = 1'000'000'003;
ll DP[1001][1001] = { 0 };

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i <= N; i++) {
        DP[0][i] = 1;
        DP[1][i] = i;
    }
    for (int i = 2; i <= K; i++) {
        DP[i][i * 2] = 2;
        for (int j = i * 2 + 1; j <= N; j++) {
            DP[i][j] = (DP[i][j - 1] + DP[i - 1][j - 3] + DP[i - 2][j - 5]) % divi;
        }
    }
    cout << DP[K][N];
}