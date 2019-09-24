#include <iostream>
using namespace std;
int N, M, A[301], G[301];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (max < A[i]) max = A[i];
    }
    int first = max, last = (100 * 300), mid, res = -1;
    while(first <= last)
    {
        mid = (first + last) / 2;
        int sum = 0, count = 0;
        for (int i = 0; i < N; i++)
        {
            if (sum + A[i] > mid)
            {
                sum = 0;
                ++count;
            }
            sum += A[i];
        }
        ++count;
        if (count <= M) res = mid, last = mid - 1;
        else first = mid + 1;
    }
    cout << res << '\n';
    int sum = 0, st = 0, c = 0;
    int* G = new int[M];
    for (int i = 0; i< N; i++)
    {
        if (sum + A[i] > res)
        {
            cout << i - st << ' ';
            st = i;
            sum = 0;
            ++c;
        }
        sum += A[i];
    }
    if(++c != M) ;
    cout << N - st;
}