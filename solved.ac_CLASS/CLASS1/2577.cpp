// 숫자의 개수
#include <iostream>
using namespace std;

int a, b, c, mod[10];

int main()
{
    cin >> a >> b >> c;
    int n = a * b * c;
    while (n)
    {
        ++mod[n % 10];
        n /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << mod[i] << '\n';
    }
}