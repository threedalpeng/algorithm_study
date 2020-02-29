// 수 정렬하기 3
#include <iostream>
using namespace std;

int n, num, arr[10001];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ++arr[num];
    }
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            cout << i << '\n';
        }
    }
}