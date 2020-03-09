// 패션왕 신해빈
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, int> closet;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, n;
    string clothes, type;
    cin >> t;
    while(t--)
    {
        closet.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> clothes >> type;
            closet[type]++;
        }
        int res = 1;
        for (auto v : closet)
        {
            res *= (v.second + 1);
        }
        cout << res - 1 << '\n';
    }
}