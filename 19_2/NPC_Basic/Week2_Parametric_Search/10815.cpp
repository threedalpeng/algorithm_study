// 숫자 카드
#include <iostream>
#include <algorithm>
using namespace std;
int N, C[5000001], M, num;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    sort(C, C + N);
    cin >> M;
    for (int i =0; i < M; i++)
    {
        cin >> num;
        int first = 0, last = N-1, mid;
        bool found = false;
        while(first <= last)
        {
            mid = (first + last) >> 1;
            if (C[mid] == num)
            {
                found = true;
                break;
            } 
            else if (C[mid] > num) last = mid - 1;
            else first = mid + 1;
        }
        cout << (found ? 1 : 0) << ' ';
    }
    return 0;
}