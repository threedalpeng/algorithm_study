#include <iostream>
using namespace std;
const int INF = 1e9;
int D[101][101];
int main()
{
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0 ; i < M; i++)
    {
        cin >> a >> b;
        D[a][b] = 1;
        D[b][a] = -1;
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = i + 1; j <= N; j++)
                if (D[i][j] != 0)
                {
                    D[i][j] = D[i][k] + D[k][j];
                    if (D[i][j] > 1) D[i][j] = 1, D[j][i] = -1;
                    else if (D[i][j] < -1) D[i][j] = -1, D[j][i] = 1;
                    else D[i][j] = 0, D[j][i] = 0;
                }

    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <=N; j++)
        {
            if (i != j && D[i][j] == 0) ++count;
        }
        cout << count << '\n';
        count = 0;
    }
}