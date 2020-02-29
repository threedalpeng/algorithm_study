// 설탕 배달
#include <iostream>
using namespace std;

int n, n5, rem;

int main()
{
    cin >> n;
    n5 = n / 5;
    rem = n % 5;
    while( (rem % 3) && n5 )
    {
        --n5;
        rem += 5;
    }
    if (rem % 3) cout << -1;
    else cout << n5 + rem / 3;
}