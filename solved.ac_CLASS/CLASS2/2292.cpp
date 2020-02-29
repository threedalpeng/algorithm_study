// 벌집
#include <iostream>
using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    --N; ++cnt;
    while ( N > 0 )
    {
        N -= 6 * cnt;
        ++cnt;
    }
    cout << cnt;
}