// 최대공약수와 최소공배수
#include <iostream>
#include <string>
using namespace std;

int a, b;

int gcd(int a, int b)
{
    int c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    cin >> a >> b;
    int c = (a > b ? gcd(b, a) : gcd(a, b));
    int d = a * b / c;
    cout << c << '\n';
    cout << d;
}