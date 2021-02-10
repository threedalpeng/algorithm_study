/**
* 개인적으로 작성한 코드 참조. 동일 코드가
* https://github.com/threedalpeng/algorithm_study 
* 에 있을 수 있음 
*/
#include <bits/stdc++.h>
using namespace std;

int dp[40];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, s, g, p, d;
    string str;
    cin >> N >> s >> g >> p >> d;
    cin >> str;

    int c1 = 0, c2 = 0, cntd = 0, startd = N;
    for (int i = N - 1; i >= 0; i--) {
        if (str[i] == 'D') {
            startd = i;
            cntd++;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < startd; i += 2) {
        switch (str[i]) {
        case 'B':
            c1 += (s - 1);
            break;
        case 'S':
            c1 += (g - 1);
            break;
        case 'G':
            c1 += (p - 1);
            break;
        case 'P':
            c1 += (d - 1);
            break;
        }
    }
    for (int i = 1; i < startd; i += 2) {
        switch (str[i]) {
        case 'B':
            c2 += (s - 1);
            break;
        case 'S':
            c2 += (g - 1);
            break;
        case 'G':
            c2 += (p - 1);
            break;
        case 'P':
            c2 += (d - 1);
            break;
        }
    }
    cout << (c1 > c2 ? c1 : c2) + cntd * 500 << '\n';
}