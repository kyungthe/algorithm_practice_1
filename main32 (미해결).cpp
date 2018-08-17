/* https://www.acmicpc.net/problem/6064 Quiz */

#include <iostream>
#include <array>

using namespace std;

int f(int M, int N, int x, int y)
{
	array<int, 10> arrX;
	array<int, 10> arrY;

	arrX[0] = x;
	arrY[0] = y;
	for (int i = 1; i < arrX.max_size(); i++)
	{
		arrX[i] = arrX[i - 1] + M % 10;
		arrY[i] = arrY[i - 1] + N % 10;
	}
}

int main()
{
	int T, M, N, x, y;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;	
		cout << f(M, N, x, y) << endl;
	}

	return 0;
}