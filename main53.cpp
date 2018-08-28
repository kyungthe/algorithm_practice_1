/* https://www.acmicpc.net/problem/2748 Quiz */

#include <iostream>

using namespace std;

unsigned long long arr[101] = { 0, 1 };

unsigned long long Fibonacci(int n)
{
	if (n == 1 || n == 0)
		return n;

	if (arr[n])
		return arr[n];

	arr[n] = Fibonacci(n - 1) + Fibonacci(n - 2);

	return arr[n];
}

int main()
{
	int n;

	cin >> n;

	cout << Fibonacci(n);

	return 0;
}