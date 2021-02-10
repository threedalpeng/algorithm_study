#include <bits/stdc++.h>
using namespace std;

string s1 = "";
string s2 = "";

int DP[1001][1001] = {
    0,
};

int main() {
    cin >> s1 >> s2;
    int lens1 = s1.length();
    int lens2 = s2.length();
    for (int j = 1; j <= lens2; j++) {
        for (int i = 1; i <= lens1; i++) {
            DP[i][j] = max(DP[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 1 : 0), max(DP[i][j - 1], DP[i - 1][j]));
        }
    }
    cout << DP[lens1][lens2] << '\n';
}