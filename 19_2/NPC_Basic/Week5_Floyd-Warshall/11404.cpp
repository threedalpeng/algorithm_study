// 플로이드
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9; /* MAX NUMBER */
int DP[101][101]; /* 그래프 */

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, a, b, c;
    cin >> n >> m;
    // 최소 직행 경로로 그래프 생성
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (DP[a][b] == 0) DP[a][b] = c;
        else DP[a][b] = min(DP[a][b], c);
    }
    // 직행 경로가 존재하지 않으면 INF로 표시
    // (시작 도시와 출발 도시가 같을 때는 제외)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (DP[i][j] == 0 && i != j) DP[i][j] = INF;

    // 최종 최소 경로 구하기 by Floyd-Warshall
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (DP[i][j] == INF ? 0 : DP[i][j]) << ' ';
        cout << '\n'; 
    }
}