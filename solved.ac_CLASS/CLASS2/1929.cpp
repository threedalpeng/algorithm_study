// 소수 구하기
#include <cmath>
#include <iostream>
using namespace std;

int M, N;
bool not_prime[1'000'001];

int main() {
    ios::sync_with_stdio(false);
    cin >> M >> N;
    not_prime[1] = true;
    for (int i = 2; i <= sqrt(N); i++) {
        if (!not_prime[i]) {
            for (int j = 2; j <= N / i; j++) {
                not_prime[i * j] = true;
            }
        }
    }
    for (int i = M; i <= N; i++) {
        if (!not_prime[i])
            cout << i << '\n';
    }
}