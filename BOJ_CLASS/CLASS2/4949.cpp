// 균형잡힌 세상
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    while (getline(cin, s)) {
        if (s == ".") break;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '(':
            case '[':
                st.push(s[i]);
                break;
            case ')':
                if (!st.empty() && st.top() == '(') st.pop();
                else
                    st.push(s[i]);
                break;
            case ']':
                if (!st.empty() && st.top() == '[') st.pop();
                else
                    st.push(s[i]);
                break;
            }
        }
        if (st.empty()) cout << "yes\n";
        else
            cout << "no\n";
    }
}