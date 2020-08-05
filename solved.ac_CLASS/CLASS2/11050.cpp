// 이항 계수 1
#include <iostream>
using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    int rst = 1;
    for (int i = n; i > n - k; i--) rst *= i;
    for (int i = 1; i <= k; i++) rst /= i;
    cout << rst;
}