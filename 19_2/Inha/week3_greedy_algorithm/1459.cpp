// 걷기
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    long long int X, Y, W, S;
    cin >> X >> Y >> W >> S;
    auto mM = minmax(X, Y);
    cout << min({ (X + Y) * W,
                  (mM.second) * S + ((X + Y) % 2) * (W - S),
                  (mM.first) * S + (mM.second - mM.first) * W });
}