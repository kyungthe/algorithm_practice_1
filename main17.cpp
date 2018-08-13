/* https://www.acmicpc.net/problem/1152 Quiz */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	char str[1000002];
	int count = 0;

	scanf_s("%[^\n]s", str, sizeof(str));

	for (size_t i = 0; i < 1000002; i++)
	{
		if (i == 0 && str[i] == 0)
			break;
		if (i == 0 && str[i] == ' ')
			continue;
		if (!str[i])
		{
			count++;
			if (str[i - 1] == ' ')
				count--;
			break;
		}
		if (str[i] == ' ')
			count++;
	}

	cout << count << endl;

	return 0;
}