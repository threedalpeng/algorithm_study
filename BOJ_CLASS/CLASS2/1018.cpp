// 체스판 다시 칠하기
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int m, n;
bool chess[51][51];

int count_wrong(int x, int y) {
    int cnt_w = 0, cnt_b = 0;
    for (int i = x; i < x + 8; i++)
        for (int j = y; j < y + 8; j++) {
            if (!chess[i][j]) ++cnt_w;
            else
                ++cnt_b;
        }
    return min(cnt_b, cnt_w);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            chess[i][j] = (s[j] == ((i + j) % 2 ? 'B' : 'W'));
        }
    }

    int mn = 1e9;
    for (int i = 0; i <= n - 8; i++)
        for (int j = 0; j <= m - 8; j++) {
            int c = count_wrong(i, j);
            if (mn > c) mn = c;
        }
    // if (mn == 1e9) mn = 0;
    cout << mn;
}