#include <iostream>
#include <cmath>
using namespace std;
int N, a[20001];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    int min = 1e9, idx = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            if (i != j)
            {
                sum += abs(a[i]-a[j]);
            }
        if (min == sum)
        {   
            if (idx == 0) idx = i;
            else if (a[idx] > a[i]) idx = i;
        }
        else if (min > sum)
        {
            min = sum;
            idx = i;
        }
    }
    cout << a[idx];
}