// 문서 검색
#include <iostream>
using namespace std;

string s, w;

int main()
{
    getline(cin, s);
    getline(cin, w);
    int cnt = 0, len = w.size();
    if (s.size() < len) cout << 0;
    else
    {
        for (int i = 0; i <= s.size() - len;)
        {
            if (s.substr(i, len) == w)
            {
                i += len;
                ++cnt;
            }
            else ++i;
        }
        cout << cnt;
    }
}