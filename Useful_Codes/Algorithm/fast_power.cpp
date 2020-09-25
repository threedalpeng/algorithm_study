#include <iostream>
using namespace std;
using ll = long long int;

ll fast_power(ll a, ll x)
{
    if (x < 0) exit(-1);
    if (x == 0) return 1;
    if (x == 1) return a;
    ll _power = fast_power(a, x >> 1);
    if (x % 2) return _power * _power * a;
    else return _power * _power;
}

int main()
{
    for (int i = 0; i < 30; i++)
    {
        cout << fast_power(2, i) << '\n';
    }
}