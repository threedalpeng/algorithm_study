// 팩토리얼 0의 개수
#include <iostream>
using namespace std;

int N;

int main()
{
    cin >> N;
    int cnt = 0;
    for (int i = 5; i <= N; i += 5)
    {
        int tmp = i;
        while(!(tmp % 5))
        {
            tmp /= 5;
            cnt++;
        }
    }
    cout << cnt;
}