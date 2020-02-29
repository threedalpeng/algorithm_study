// 스택 수열
#include <iostream>
#include <stack>
using namespace std;

int n, t;
stack<int> S;
string res;

int main()
{
    cin >> n;
    int cur = 1;
    S.push(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        while(cur <= t)
        {
            S.push(cur);
            res += "+\n";
            cur++;
        }
        if (S.top() != t)
        {
            cout << "NO";
            return 0;
        }
        S.pop();
        res += "-\n";
    }
    cout << res;
}