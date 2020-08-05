// 보물
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int* A = new int[N];
    int* B = new int[N];
    for (int i = 0; i < N; i++) cin>>A[i];
    for (int i = 0; i < N; i++) cin>>B[i];
    sort(A, A+N);
    sort(B, B+N, greater<int>());
    int sum = 0;
    for (int i = 0; i < N; i++) sum += A[i]*B[i];
    cout << sum;
}