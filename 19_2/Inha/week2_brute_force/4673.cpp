// 셀프 넘버
#include <iostream>
using namespace std;

bool is_self[10001];

int self_number(int n)
{
    int self = n;
    while(n)
    {
        self += n % 10;
        n /= 10;
    }
    return self;
}

int main()
{
    int n;
    for (int i = 1; i < 10000; i++)
    {
        if ((n = self_number(i)) <= 10000)
            is_self[n] = true;
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (!is_self[i])
            cout << i << '\n';
    }
}