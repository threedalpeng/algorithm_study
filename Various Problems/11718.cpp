// 그대로 출력하기
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (getline(cin, s))
        cout << s << endl;
}