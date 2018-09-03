/* https://www.acmicpc.net/problem/11051 Quiz */

#include <iostream>

using namespace std;

int coefficient[1001][1001]; // 이전계수 [현재지수][현재지수-1]

int main()
{
	int N, K;

	cin >> N >> K;

	coefficient[1][0] = coefficient[1][1] = 1;	// (x+1)의 1제곱 계수를 저장
	for (int i = 2; i <= N; i++)				// (x+1)의 i 제곱일 때
	{
		coefficient[i][0] = 1;					// 지수가 0 이면 계수는 무조건 1
		for (int j = 1; j < i + 1; j++)			// (x+1)의 i 제곱은 수의 갯수가 i+1개
		{
			coefficient[i][j] = coefficient[i - 1][j] + coefficient[i - 1][j - 1];
			coefficient[i][j] %= 10007;
		}
	}

	cout << coefficient[N][K] << "\n";

	return 0;
}