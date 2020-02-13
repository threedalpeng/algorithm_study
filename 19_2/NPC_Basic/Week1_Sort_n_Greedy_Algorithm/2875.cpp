// 대회 or 인턴
#include <iostream>

using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	int nTeam = ((N - 2 * M) >= 0) ? M : (N / 2);
	int over = K - (N + M - 3 * nTeam);
	nTeam -= ((over > 0 ? over : 0) + 2) / 3;
	cout << nTeam << endl;
}