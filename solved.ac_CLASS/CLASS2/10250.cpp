// ACM 호텔
#include <iostream>
using namespace std;

int t, h, w, n;

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;
        int f = n % h;
        int no = n / h + 1;
        if (f == 0)
        {
            f = h;
            --no;
        }
        cout << f * 100 + no << '\n';
    }
}