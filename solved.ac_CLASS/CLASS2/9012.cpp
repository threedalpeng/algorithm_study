// 괄호
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string s;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            switch(s[i])
            {
            case '(':
                st.push(s[i]); break;
            case ')':
                if (!st.empty() && st.top() == '(') st.pop();
                else st.push(s[i]);
                break;
            }
        }
        if (st.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}