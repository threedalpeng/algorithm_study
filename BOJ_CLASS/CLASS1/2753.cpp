// 윤년
#include <iostream>
using namespace std;

int year;

int main() {
    cin >> year;
    cout << (!(year % 4) && !(year % 400 && !(year % 100)) ? 1 : 0);
}