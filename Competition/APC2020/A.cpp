/**
* 개인적으로 작성한 코드 참조. 동일 코드가
* https://github.com/threedalpeng/algorithm_study 
* 에 있을 수 있음 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll X1, X2, m, seed, a, c, s1, s2;
    cin >> m >> seed >> X1 >> X2;
    if (X1 != seed) {
        a = 0;
        s1 = X2 - X1;
        s2 = X1 - seed;
        while(s1 % m) {a++; s1-=s2;}
        c = (X1 - a * seed) % m;
        c = (c < 0 ? m + c : c);
    }
    else {
        a = 2;
        c = m - seed;
    }
    cout << a << ' ' << c;

}