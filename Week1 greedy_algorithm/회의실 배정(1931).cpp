#include <iostream>
#include <priority>
using namespace std;

void sort_by_end(Meet* meets, int first, int last)
{
    if (first < last)
    {
        int mid = partition(meets, first, last);
        sort_by_end(meets, first, mid-1);
        sort_by_end(meets, mid+1, last);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    Meet* meets = new Meet[N];
    for (int i = 0; i < N; i++)
    {
        cin >> meets[i].start >> meets[i].end;
    }

    sort_by_end(meets, 0, N-1);

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