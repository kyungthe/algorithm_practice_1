/* https://www.acmicpc.net/problem/4673 Quiz */

#include <iostream>

using namespace std;

int selfnumbers[10036];

int SelfNumber(int n)
{
	int result = 0;
	int temp = n;

	result += n;

	while (temp)
	{
		result += temp % 10;
		temp /= 10;
	}

	return result;
}

int main()
{
	for (int i = 1; i <= 10000; i++)
		selfnumbers[SelfNumber(i)]++;

	for (size_t i = 1; i <= 10000; i++)
	{
		if (!selfnumbers[i])
			cout << i << endl;
	}

	return 0;
}