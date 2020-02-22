// 단어 공부
#include <iostream>
#include <string>
using namespace std;

string s;
int abc[26], mx, midx;
bool multi;

int ctoi(char c)
{
    if ('a' <= c && c <= 'z') return c - 'a';
    else if ('A' <= c && c <= 'Z') return c - 'A';
    else return -1;
}

int main()
{
    cin >> s;
    for (auto c : s)
    {
        ++abc[ctoi(c)];
    }
    for (int i = 0; i < 26; i++)
    {
        if (mx < abc[i])
        {
            mx = abc[i];
            midx = i;
            multi = false;
        }
        else if (mx == abc[i])
        {
            multi = true;
        }
    }

    cout << ( multi ? '?' : static_cast<char>(midx + 'A') );
}