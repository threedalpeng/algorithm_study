// 상수
#include <iostream>
using namespace std;

int a, b, am, bm;

int main()
{
    cin >> a >> b;
    while (a)
    {
        am *= 10;
        am += a % 10;
        a /= 10;
    }
    while (b)
    {
        bm *= 10;
        bm += b % 10;
        b /= 10;
    }
    cout << (am > bm ? am : bm);
}