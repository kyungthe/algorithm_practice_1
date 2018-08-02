/* https://algospot.com/judge/problem/read/CLOCKSYNC ¹®Á¦ */

#include <iostream>

using namespace std;

int clock[16];
int clockCount[16], result, min = 0x7FFFFFFF;
int clockSwitch[10][16] = {
	{ 3, 3, 3, 0, },
	{ 0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0 },
	{ 3, 0, 0, 0, 3, 3, 3, 3, 0, },
	{ 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 3, 0, 3, 0, },
	{ 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3 },
	{ 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3 },
	{ 0, 0, 0, 0, 3, 3, 0, 3, 0, 0, 0, 0, 0, 0, 3, 3 },
	{ 0, 3, 3, 3, 3, 3, 0, },
	{ 0, 0, 0, 3, 3, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0 }
};

void rotation()
{
	bool finished = false;

	for (size_t i = 0; i < 16; i++)
	{
		if (clockCount[i] >= 3)
			return ;

		clockCount[i]++;
		result++;

		for (size_t j = 0; j < 16; j++)
		{
			clock[j] += clockSwitch[i][j];
			if (clock[j] > 12)
				clock[j] = 3;
			if (clock[j] != 12)
				finished = false;
		}

		if (finished)
		{
			if (result < min)
				min = result;
			return;
		}

		rotation();

		clockCount[i]--;
		result--;

		for (size_t j = 0; j < 16; j++)
		{
			clock[j] -= clockSwitch[i][j];
		}
	}
}

void input()
{
	for (size_t i = 0; i < 16; i++)
	{
		cin >> clock[i];
	}
}

void output()
{
	cout << min << endl;
}

int main()
{
	input();
	for (size_t i = 0; i < 16; i++)
	{
		rotation();
	}
	output();

	return 0;
}