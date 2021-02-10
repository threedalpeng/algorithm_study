#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Answer;
vector<int> A, B;

int main(int argc, char** argv) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T, test_case;
    int K, N;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        cin >> N >> K;
        A.resize(N);
        B.resize(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (int i = 0; i < K; i++)
            A[i] += B[K - i - 1];

        sort(A.begin(), A.begin() + K, greater<int>());
        Answer = A[0];

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}