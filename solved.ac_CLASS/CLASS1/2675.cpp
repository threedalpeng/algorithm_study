// 문자열 반복
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t, r;
    string s, p;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        p.clear();
        cin >> r >> s;
        for (auto x : s)
        {
            for (int j = 0; j < r; j++)
            {
                p += x;
            }
        }
        cout << p << '\n';
    }
}