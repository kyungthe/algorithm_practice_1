/* https://www.acmicpc.net/problem/11050 Quiz */

#include <iostream>

using namespace std;

int main()
{
	int N, K;
	
	cin >> N >> K;

	int n, n_k;
	n = n_k = 1;

	for (int i = N; i > K; i--)
		n *= i;
	for (int i = N - K; i > 0; i--)
		n_k *= i;

	cout << n / n_k << "\n";

	return 0;
}