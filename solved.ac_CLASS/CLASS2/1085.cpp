// 직사각형에서 탈출
#include <iostream>
using namespace std;

int main()
{
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int x_reach, y_reach;
	int reach;

	if (x < w-x) {
		x_reach = x;
	}
	else {
		x_reach = w-x;
	}
	if (y < h-y) {
		y_reach = y;
	}
	else {
		y_reach = h - y;
	}
	
	if (x_reach < y_reach) {
		reach = x_reach;
	}
	else {
		reach = y_reach;
	}
	cout << reach << endl;

	return 0;
}