// 피보나치 함수
#include <iostream>
#include <cstring>
using namespace std;

struct Count{ int zero = 0, one = 0; };

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, N;
    Count *F = new Count[41];
    F[0] = {1, 0};
    F[1] = {0, 1};
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int j = 2; j <= N; j++)
        {
            if (F[j].zero == 0 && F[j].one == 0)
            {
                F[j].zero = F[j - 1].zero + F[j - 2].zero;
                F[j].one = F[j - 1].one + F[j - 2].one;
            }
        }
        cout << F[N].zero << ' ' << F[N].one << '\n'; 
    }
}