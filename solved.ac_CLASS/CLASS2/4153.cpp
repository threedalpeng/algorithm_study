// 직각삼각형
#include <iostream>
using namespace std;

int a, b, c;

int main()
{
    cin >> a >> b >> c;
    while (a || b || c)
    {
        a = a * a;
        b = b * b;
        c = c * c;
        if (a + b == c || b + c == a || c + a == b)
            cout << "right" << '\n';
        else 
            cout << "wrong" << '\n';
        cin >> a >> b >> c;
    }
}