/* https://www.acmicpc.net/problem/11050 Quiz */

#include <iostream>

using namespace std;

int main()
{
	int N, K;
	
	cin >> N >> K;

	int n, k, n_k;
	n = k = n_k = 1;

	for (int i = 1; i <= N; i++)
		n *= i;
	for (int i = 1; i <= K; i++)
		k *= i;
	for (int i = 1; i <= N - K; i++)
		n_k *= i;

	cout << n / (k * n_k) << "\n";

	return 0;
}