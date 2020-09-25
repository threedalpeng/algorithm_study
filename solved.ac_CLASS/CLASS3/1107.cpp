// 리모컨
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int N, M;
bool bt[10];

bool check_digit(int digit)
{
    if (digit < 0)
        return false;
    if (digit == 0 && !bt[0])
        return false;
    while (digit)
    {
        if (!bt[digit % 10])
            return false;
        digit /= 10;
    }
    return true;
}
int get_length(int digit)
{
    int c = 0;
    if (digit == 0)
        c = 1;
    while (digit)
    {
        ++c;
        digit /= 10;
    }
    return c;
}
int get_dist(int digit, int N)
{
    return abs(digit - N) + get_length(digit);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    int b;
    for (int i = 0; i <= 9; i++)
        bt[i] = true;
    for (int i = 0; i < M; i++)
    {
        cin >> b;
        bt[b] = false;
    }
    int mn = abs(N - 100);
    if (!check_digit(N))
    {
        int d1 = N, d2 = N;
        int count = 0;
        do
        {
            --d1;
            ++d2;
            ++count;
            if (check_digit(d1) || check_digit(d2) || count > mn)
                break;
        } while (true);

        if (count <= mn)
        {
            if (check_digit(d1))
                mn = min(get_dist(d1, N), mn);
            if (check_digit(d2))
                mn = min(get_dist(d2, N), mn);
        }
    }
    else
    {
        mn = min(get_dist(N, N), mn);
    }

    cout << mn << '\n';
}