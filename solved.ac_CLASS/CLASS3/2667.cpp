// 단지번호붙이기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> map;
vector<int> v;

void dfs(int x, int y)
{
    if (x < 0 || N <= x || y < 0 || N <= y) return;
    if (map[x][y] != '1') return;
    map[x][y] = '2';
    ++*(v.rbegin());
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x + 1, y);
}

int main()
{
    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        map.push_back(s);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == '1')
            {
                v.push_back(0);
                dfs(i, j);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto i : v)
    {
        cout << i << '\n';
    }
}