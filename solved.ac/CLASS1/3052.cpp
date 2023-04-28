// 나머지
#include <iostream>
using namespace std;

int num, mod[42], cnt;

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> num;
        ++mod[num % 42];
    }
    for (auto x : mod) {
        if (x) ++cnt;
    }
    cout << cnt;
}