#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char** argv) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}