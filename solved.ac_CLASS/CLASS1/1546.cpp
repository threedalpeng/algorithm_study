// 평균
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int N, scores[1001], mx;

int main() {
    cin >> N;
    double avg = 0;
    for (int i = 1; i <= N; i++) {
        cin >> scores[i];
        avg += scores[i];
        if (mx < scores[i]) mx = scores[i];
    }
    avg /= N;
    cout << fixed << setprecision(6) << avg / mx * 100;
}