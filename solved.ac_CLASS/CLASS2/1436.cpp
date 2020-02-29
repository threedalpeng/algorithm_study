// 영화감독 숌
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    ll idx = 665, cnt = 0;
    while (cnt != n)
    {
        string s = to_string(++idx);
        if (s.find("666"s) != string::npos)
            ++cnt;
    }
    cout << idx;
}