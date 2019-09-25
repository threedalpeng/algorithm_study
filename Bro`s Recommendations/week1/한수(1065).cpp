#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = (N >= 100 ? 99 : N);
    for (int i = 100; i <= N; i++)
    {
        int n100 = i / 100;
        int n10 = (i % 100) / 10;
        int n1 = i % 10;
        if (n100 - n10 == n10 - n1) ++count;
    }
    cout << count;
    return 0;
}