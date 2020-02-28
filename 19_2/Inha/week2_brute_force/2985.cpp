// 세 수
#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B, C;
    char f, b;
    cin >> A >> B >> C;
    if      (A + B == C) f = '+', b = '=';
    else if (A - B == C) f = '-', b = '=';
    else if (A * B == C) f = '*', b = '=';
    else if (A / B == C) f = '/', b = '=';
    else if (A == B + C) f = '=', b = '+';
    else if (A == B - C) f = '=', b = '-';
    else if (A == B * C) f = '=', b = '*';
    else if (A == B / C) f = '=', b = '/';
    cout << A << f << B << b << C;
}