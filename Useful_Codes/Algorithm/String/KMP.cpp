#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findPattern(string s, string p)
{
    int len_s = s.length();
    int len_p = p.length();
    vector<int> fail(len_p);

    for (int i = 1, j = 0; i < len_p; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = fail[j - 1];
        if (p[i] == p[j])
            fail[i] = ++j;
    }

    vector<int> result;
    for (int i = 0, j = 0; i < len_s; i++)
    {
        while (j > 0 && s[i] != p[i])
            j = fail[j - 1];
        if (s[i] == p[i])
        {
            if (j == len_p - 1)
            {
                result.push_back(i - len_p + 2);
                j = fail[j];
            }
        }
        else
            j++;
    }

    for (auto i : result)
    {
        cout << i << ' ';
    }
    cout << '\n';
    if (result.empty())
        return -1;
    else
        return result[0];
}

int main()
{
    string str = "AHAHAHAHAHEEAHEAHAHA";
    string pat = "AHEE";
    cout << findPattern(str, pat);
}