// 거스름돈
#include <iostream>
using namespace std;

int main()
{
    int N, cnt = 0;
    int unit[6] = {500, 100, 50, 10, 5, 1};
    cin >> N;
    N = 1000 - N;
    for (int i = 0 ; i < 6 ; i++)
    {
        while (unit[i] <= N)
        {
            N -= unit[i];
            ++cnt;
        }
        if (!N) break;
    }
    cout << cnt;
}