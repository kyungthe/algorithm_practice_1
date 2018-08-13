/* https://www.acmicpc.net/problem/2920 ¹®Á¦ */

#include <iostream>
#include <string>
#include <array>

using namespace std;

string f(array<int, 8> arr)
{
	int def;

	def = arr[1] - arr[0];
	for (size_t i = 2; i < arr.max_size(); i++)
	{
		if (arr[i] - arr[i - 1] != def)
			return "mixed";
	}

	if (def == 1) return "ascending";
	else return "descending";
}

int main()
{
	array<int, 8> arr;

	for (size_t i = 0; i < arr.max_size(); i++)
	{
		cin >> arr[i];
	}

	cout << f(arr) << endl;

	return 0;
}