// 가장 긴 증가하는 부분 수열
#include <iostream>
using namespace std;

int A[1001], L[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    L[0] = 1;
    int max = 1;
    for (int i = 1; i < N; i++) {
        int m = 0;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && m < L[j])
                m = L[j];
        }
        L[i] = m + 1;
        if (max < L[i]) max = L[i];
    }
    cout << max;
}