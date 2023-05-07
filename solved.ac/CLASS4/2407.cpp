// 통계학
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

string memo[101][101] = { "" };

string add(const string& a, const string& b) {
    size_t aLen = a.size();
    size_t bLen = b.size();

    string result = "";
    char carry = 0;
    for (int i = 0; i < aLen || i < bLen; i++) {
        char aIdx = aLen - 1 - i;
        char aDigit = (aIdx >= 0 ? a[aIdx] - '0' : 0);
        char bIdx = bLen - 1 - i;
        char bDigit = (bIdx >= 0 ? b[bIdx] - '0' : 0);
        char rDigit = aDigit + bDigit + carry;
        if (rDigit >= 10) {
            carry = 1;
            rDigit -= 10;
        }
        else {
            carry = 0;
        }
        result.push_back(rDigit + '0');
    }
    if (carry == 1) {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}

string nCr(int n, int r) {
    if (r == 0 || r == n) return "1";
    if (memo[n][r] == "")
        memo[n][r] = add(nCr(n - 1, r), nCr(n - 1, r - 1));
    return memo[n][r];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    cout << nCr(n, m) << '\n';
}