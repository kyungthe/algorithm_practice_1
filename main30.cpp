/* https://www.acmicpc.net/problem/10250 Quiz */

#include <iostream>

using namespace std;

void f(int h, int w, int n)
{
	int Y, X;
	
	n--;
	Y = n % h + 1;
	X = n / h + 1;	

	printf("%d%02d\n", Y, X);
}

int main()
{
	int T;

	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		int H, W, N;
		cin >> H >> W >> N;
		f(H, W, N);
	}
	return 0;
}