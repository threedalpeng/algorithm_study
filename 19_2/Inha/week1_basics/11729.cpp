// 하노이 탑 이동 순서
#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int src, int dest, int temp, int N)
{
    if (N == 0) return;
    hanoi(src, temp, dest, N-1);
    cout << src << ' ' << dest << '\n';
    hanoi(temp, dest, src, N-1);
}

int main()
{
    int N;
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    cout << static_cast<int>(pow(2,N)-1) << '\n';
    hanoi(1, 3, 2, N);
}