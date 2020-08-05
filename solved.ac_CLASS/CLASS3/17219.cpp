// 비밀번호 찾기
#include <iostream>
#include <map>
using namespace std;

int n, m;
string ad, pass;
map<string, string> pass_map;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ad >> pass;
        pass_map[ad] = pass;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> ad;
        cout << pass_map[ad] << '\n';
    }
}