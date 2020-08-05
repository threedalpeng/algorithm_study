// 용돈 관리
#include <iostream>
using namespace std;

int N, M, amount[100'001];

bool pos(int a)
{
    int cnt = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += amount[i];
        if (sum > a)
        {
            sum = amount[i];
            ++cnt;
            if (cnt > M)
            {
                return false;
            }
        }
    }
    ++cnt;
    if (cnt > M)
    {
        return false;
    }
    return true;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    int sum = 0, mx = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> amount[i];
        sum += amount[i];
        mx = (mx >= amount[i] ? mx : amount[i]);
    }
    
    int first = mx, last =  sum, res = -1;
    while (first <= last)
    {
        int mid = (first + last) >> 1;
        if (pos(mid)) last = mid - 1, res = mid;
        else first = mid + 1;
    }
    cout << res;
} 