// 음계
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, a = "12345678", d = "87654321";
    char c;
    for (int i = 0; i < 8; i++)
    {
        cin >> c;
        s += c;
    }
    if (s == a) cout << "ascending";
    else if (s == d) cout << "descending";
    else cout << "mixed";
}