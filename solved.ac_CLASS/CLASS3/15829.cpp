// Hashing
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int l;
const ll M = 1234567891;
ll pow_list[50];
string s;

ll myhash(string s)
{
    ll sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += (s[i] - 'a' + 1) * pow_list[i];
        sum %= M;
    }
    return sum % M;
}

int main()
{
    cin >> l;
    cin >> s;
    pow_list[0] = 1;
    for (int i = 1; i < l; i++)
    {
        pow_list[i] = (pow_list[i - 1] * 31) % M;
    }
    cout << myhash(s);
}