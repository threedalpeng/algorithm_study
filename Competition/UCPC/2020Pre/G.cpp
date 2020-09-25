// 루머 / 19538
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a;
vector<int> graph[200'001];
bool visited[200'001];
queue<int> Q;

bool is_infected(int m)
{
    int count = 0;
    for (auto i : graph[m])
    {
        if (visited[i])
            ++count;
    }
    return 2 * count >= graph[m].size();
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        while (a != 0)
        {
            graph[i].push_back(a);
            cin >> a;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        visited[a] = true;
        for (auto j : graph[a])
        {
            Q.push()
        }
    }

    int depth = 0;
    int size = Q.size();
    for (int i = 0; i < size; i++)
    {
        int adj = Q.front();
        Q.pop();
        if (is_infected(adj))
        {
            
        }
    }
}