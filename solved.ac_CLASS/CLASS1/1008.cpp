// A/B
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	cout << setprecision(10) << A / (double)B;
}