// 분해합
#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, sum = 0, num;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        num = i;
        sum += i;
        while(num)
        {
            sum += num % 10;
            num /= 10;
        }
        if (sum == N)
        {
            num = i;
            break;
        }
        sum = 0;
    }
    cout << num;
}