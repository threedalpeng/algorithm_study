// Cosmetic Survey
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int m, n;
int srv[501][501];
int DP[501][501];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> srv[i][j];
            if (srv[i][j] == 0) srv[i][j] = INF;
        }
    
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            for (int k = 1; k <= n; k++)
            {
                if (srv[k][i] > srv[k][j]) ++DP[i][j];
                else if (srv[k][i] < srv[k][j]) ++DP[j][i];
            }

    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
        {
            if (DP[i][j] > DP[j][i]) DP[j][i] = 0;
            else if (DP[i][j] < DP[j][i]) DP[i][j] = 0;
            else { DP[i][j] = 0; DP[j][i] = 0; }
        }

    for (int k = 1; k <= m; k++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
            {
                DP[i][j] = max(DP[i][j], min(DP[i][k], DP[k][j]));
            }

    bool isMostPrf;
    int max = 0;
    vector<int> cos;
    for (int i = 1; i <= m; i++)
    {
        isMostPrf = true;
        for (int j = 1; j <= m; j++)
        {
            if (DP[j][i] < DP[i][j]) 
            {
                isMostPrf = false;
                break;
            }
        }
        if (isMostPrf) cos.push_back(i);
    }
    for (auto x : cos)
    {
        cout << x << ' ';
    }
}