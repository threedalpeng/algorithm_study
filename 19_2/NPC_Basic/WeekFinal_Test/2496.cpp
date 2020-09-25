#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    for (int i = 0; i < 3; i++)
    {
        int cnt = 0, max = 0;
        char c = ' ';
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            if (c != s[j]) 
            {
                if (max < cnt) max = cnt;
                cnt = 1;
                c = s[j];
            }
            else ++cnt;
        }
        if (max < cnt) max = cnt;
        cout << max << '\n';
    }
}