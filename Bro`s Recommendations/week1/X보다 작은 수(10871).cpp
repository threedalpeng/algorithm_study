#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, X, num;
    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (num < X) cout << num << ' ';
    } 
}