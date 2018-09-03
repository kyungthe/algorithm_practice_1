/* https://www.acmicpc.net/problem/11051 Quiz */

#include <iostream>

using namespace std;

int coefficient[1001][1001]; // ������� [��������][��������-1]

int main()
{
	int N, K;

	cin >> N >> K;

	coefficient[1][0] = coefficient[1][1] = 1;	// (x+1)�� 1���� ����� ����
	for (int i = 2; i <= N; i++)				// (x+1)�� i ������ ��
	{
		coefficient[i][0] = 1;					// ������ 0 �̸� ����� ������ 1
		for (int j = 1; j < i + 1; j++)			// (x+1)�� i ������ ���� ������ i+1��
		{
			coefficient[i][j] = coefficient[i - 1][j] + coefficient[i - 1][j - 1];
			coefficient[i][j] %= 10007;
		}
	}

	cout << coefficient[N][K] << "\n";

	return 0;
}