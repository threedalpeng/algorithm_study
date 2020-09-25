// 이중 우선순위 큐
#include <iostream>
#include <set>
#define endl '\n'
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, k;
    ll n;
    char op;
    cin >> T;
    while (T--)
    {
        multiset<ll> dpq;
        cin >> k;
        while (k--)
        {
            cin >> op >> n;
            if (op == 'D' && !dpq.empty())
            {
                if (n == 1)
                {
                    dpq.erase(--(dpq.end()));
                }
                else if (n == -1)
                {
                    dpq.erase(dpq.begin());
                }
            }
            else if (op == 'I')
            {
                dpq.insert(n);
            }
        }
        if (dpq.empty())
            cout << "EMPTY\n";
        else
            cout << *(--dpq.end()) << ' '
                 << *(dpq.begin()) << endl;
    }
}