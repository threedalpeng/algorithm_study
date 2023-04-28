// 1로 만들기
#include <algorithm>
#include <iostream>
using namespace std;

int N;
int arr[1'000'001];

int main() {
    cin >> N;
    fill(arr + 1, arr + N + 1, 1e6);
    arr[1] = 0;
    for (int i = 1; i < N; i++) {
        arr[i + 1] = min(arr[i + 1], arr[i] + 1);
        if (i * 2 <= N) arr[i * 2] = min(arr[i * 2], arr[i] + 1);
        if (i * 3 <= N) arr[i * 3] = min(arr[i * 3], arr[i] + 1);
    }
    cout << arr[N];
}