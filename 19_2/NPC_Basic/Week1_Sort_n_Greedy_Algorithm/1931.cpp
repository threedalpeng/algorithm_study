// 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _Meet
{
    int start;
    int end;
} Meet;

bool compare(Meet m1, Meet m2)
{
    if (m1.end == m2.end)
    {
        return m1.start < m2.start;
    }
    else
    {
        return m1.end < m2.end;
    }
}

int main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Meet> meets;
    for (int i = 0; i < N; i++)
    {
        Meet newMeet;
        cin >> newMeet.start >> newMeet.end;
        meets.push_back(newMeet);
    }

    sort(meets.begin(), meets.end(), compare);

    int count = 0;
    int prev_idx = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            count++;
        }
        else
        {
            if (meets[prev_idx].end <= meets[i].start)
            {
                prev_idx = i;
                count++;
            }
        }
    }
    
    cout << count << '\n';
}