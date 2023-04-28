// 별 찍기 - 1
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int counter = 1;
    while (counter != N + 1) {
        for (int i = 1; i <= counter; i++) {
            cout << '*';
        }
        cout << endl;
        counter++;
    }

    return 0;
}