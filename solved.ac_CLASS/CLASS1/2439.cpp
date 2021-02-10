// 별 찍기 - 2
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int counter = 1;
    while (counter != N + 1) {
        for (int j = 1; j <= N - counter; j++) {
            cout << ' ';
        }
        for (int i = 1; i <= counter; i++) {
            cout << '*';
        }
        cout << endl;
        counter++;
    }

    return 0;
}