#include <iostream>
using namespace std;

int A[1001], L[1001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    L[0] = 1;
    for (int i = 1; i < N; i++)
    {
        L[i] = 1;
        for (int j = i-1; j >= 0; j--)
        {
            if (A[i] > A[j])
            {
                L[i] = L[j] + 1;
                break;
            }
            else if (A[i] == A[j])
            {
                L[i] = L[j];
                break;
            }
        }
    }
    
    cout << L[N-1];
    // 20 10 30 0 40
    // 1  1  2  1  3
}