/* https://www.acmicpc.net/problem/2839 ¹®Á¦ */

#include <iostream>
#define NOT_FOUND	99999
#define SUGARMAX	5001

using namespace std;

int sugars[SUGARMAX];

int min(int a, int b)
{
	return a < b ? a : b;
}

int solve(int sugar, int count)
{
	if (sugar < 0)
		return NOT_FOUND;
	else if (sugar == 0)
		return count;

	if (count >= sugars[sugar])
		return NOT_FOUND;

	sugars[sugar] = count;

	int result;

	result = min(solve(sugar - 3, count + 1), solve(sugar - 5, count + 1));

	return result;
}

int main()
{
	int N, result;

	cin >> N;

	for (size_t i = 0; i < SUGARMAX; i++)
		sugars[i] = NOT_FOUND;

	result = solve(N, 0);

	if (result == NOT_FOUND)
		result = -1;

	cout << result << endl;

	return 0;
}