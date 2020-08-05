// 최댓값
#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int num, mx = 0, idx = 0;
    for (int i = 1; i <= 9; i++)
    {
        cin >> num;
        if (num > mx)
        {
            mx = num;
            idx = i;
        }
    }
    cout << mx << '\n' << idx;
}