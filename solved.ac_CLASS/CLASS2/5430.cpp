// AC
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int T, n, in;
deque<string> x;
string p, xs;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--)
    {
        cin >> p;
        cin >> n;
        cin >> xs;
        if (n)
        {
            int st = 1;
            for (int i = 1; i < xs.size(); i++)
            {
                if (xs[i] == ',' || xs[i] == ']')
                {
                    x.push_back(xs.substr(st, i - st));
                    st = i + 1;
                }
            }
        }
        bool error = false, reversed = false;
        for (auto c : p)
        {
            if (c == 'R')
            {
                reversed = !reversed;
            }
            else if (c == 'D')
            {
                if (x.size())
                {
                    if (reversed)
                        x.pop_back();
                    else
                        x.pop_front();
                }
                else
                {
                    error = true;
                    break;
                }
            }
        }
        if (error)
        {
            cout << "error\n";
        }
        else
        {
            if (reversed)
                reverse(x.begin(), x.end());
            if (!x.size())
            {
                cout << "[]";
            }
            else
            {
                cout << '[';
                for (auto it = x.begin(); it < x.end(); it++)
                {
                    cout << *it;
                    if (it == x.end()-1) cout << ']';
                    else cout << ',';
                }
            }
            cout << '\n';
        }
        x.clear();
    }
}   