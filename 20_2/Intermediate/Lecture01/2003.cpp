// 수들의 합 2
#include <iostream>
using namespace std;

int N, M, A[10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int count = 0, sum = A[0];
    int i = 0, j = 0;
    while (j < N) {
        if (sum < M) {
            sum += A[++j];
        }
        else if (sum == M) {
            ++count;
            sum += A[++j];
            sum -= A[i++];
        }
        else {
            sum -= A[i++];
        }
    }
    cout << count << '\n';
}