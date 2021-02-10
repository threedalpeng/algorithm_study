// 블랙잭
#include <iostream>
using namespace std;

int N, M, sum, cards[101];
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
        sum += cards[i];
    }
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum_of_three = cards[i] + cards[j] + cards[k];
                if (M >= sum_of_three && sum_of_three > max)
                    max = sum_of_three;
            }
        }
    }
    cout << max;
}
