// 수학은 비대면강의입니다 / 19532
#include <iostream>
using namespace std;

int a, b, c, d, e, f, x, y;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d >> e >> f;
    int m = b * d - a * e, n = c * d - a * f;
    if (m == 0)
        if (c == 0)
            y = 0;
        else
            y = c / b;
    else
        y = n / m;
    if (a == 0)
        if (d == 0)
            x = 0;
        else
            x = (f - e * y) / d;
    else
        x = (c - b * y) / a;
    cout << x << ' ' << y << '\n';
}