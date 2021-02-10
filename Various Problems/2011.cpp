#include <iostream>
#include <string>
using namespace std;
using ll = long long;

ll decode(string input) {
    long long dp[5001] = {
        0,
    };
    if (input[0] == '0') return 0;
    dp[0] = 1;
    if (!input[1]) return dp[0];
    dp[1] = (input[1] == '0' ? 0 : dp[0]);
    if (input[0] == '1' || (input[0] == '2' && input[1] <= '6'))
        ++dp[1];
    int idx = 2;
    while (input[idx]) {
        dp[idx] = (input[idx] == '0' ? 0 : dp[idx - 1]);
        if (input[idx - 1] == '1' || (input[idx - 1] == '2' && input[idx] <= '6'))
            dp[idx] += dp[idx - 2];
        dp[idx] %= 1'000'000;
        ++idx;
    }
    return dp[idx - 1];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string code;
    cin >> code;
    cout << decode(code);
    return 0;
}