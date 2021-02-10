// 평균은 넘겠지
#include <cstdio>
int C, N, s[1002], count;
double avg;

int main() {
    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        scanf("%d", &N);
        avg = 0;
        count = 0;
        for (int j = 0; j < N; j++) {
            scanf("%d", &s[j]);
            avg += s[j];
        }
        avg /= N;
        for (int j = 0; j < N; j++) {
            if (avg < s[j]) ++count;
        }
        printf("%.3lf%c\n", (double)count / N * 100, '%');
    }
}