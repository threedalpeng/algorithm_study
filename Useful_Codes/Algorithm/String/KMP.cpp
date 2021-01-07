#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> findPattern(string s, string p)
{
    int len_s = s.length();
    int len_p = p.length();
    vector<int> fail(len_p, 0);

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
        while (j > 0 && s[i] != p[j])
            j = fail[j - 1];
        if (s[i] == p[j])
        {
            if (j == len_p - 1)
            {
                result.push_back(i - len_p + 1);
                j = fail[j];
            }
            else
                j++;
        }
    }
    return result;
}

int main()
{
    string str = "ababababacababca";
    string pat = "abab";

    for (auto i : findPattern(str, pat))
    {
        cout << i << ' ';
    }
    cout << '\n';
}