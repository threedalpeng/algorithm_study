// 계단 오르기
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, step[301], score[301];
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> step[i];
    score[0] = 0;
    score[1] = step[1];
    score[2] = step[1] + step[2];
    for (int i = 3; i <= N; i++)
    {
        score[i] = max(score[i - 2] + step[i], score[i - 3] + step[i - 1] + step[i]);
    }
    cout << score[N];
}