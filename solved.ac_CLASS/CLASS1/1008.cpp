// A/B
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    cout << setprecision(10) << A / (double)B;
}