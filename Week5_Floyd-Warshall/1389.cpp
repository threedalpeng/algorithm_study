// 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <algorithm>
using namespace std;

int kbn[101][101];
const int INF = 1e9;

int main()
{
    int N, M, A, B, mp = 1;
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A >> B;
        kbn[A][B] = 1;
        kbn[B][A] = 1;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (kbn[i][j] == 0 && i != j) kbn[i][j] = INF;
    
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                kbn[i][j] = min(kbn[i][j], kbn[i][k] + kbn[k][j]);
    
    kbn[0][0] = INF; // minimum kbn
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            kbn[i][0] += kbn[i][j]; // kbn of each person
        if (kbn[0][0] > kbn[i][0])
        {
            kbn[0][0] = kbn[i][0];
            mp = i;
        }
    }
    
    cout << mp;
}