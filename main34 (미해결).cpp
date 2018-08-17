/* https://www.acmicpc.net/problem/2108 Quiz */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int Mode(vector<int>& v)
{
	int count = 1;
	int max1 = v[0];
	int i1 = 0;
	int max2 = v[0];
	int i2 = 0;

	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1])
			count++;
		else if (count > max1)
		{
			max1 = count;
			count = 1;
			i1 = i;
		}
	}

	count = 1;

	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1] && v[i] != v[i1])
			count++;
		else if (count > max2 && v[i] != v[i1])
		{
			max2 = count;
			count = 1;
			i2 = i;
		}
	}

	if (max1 == max2)
	{
		if (v[i1] > v[i2])
			return v[i2];
		else
			return v[i1];
	}
	else
		return v[i1];
}

int main()
{
	int N;
	int total = 0;

	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		total += v[i];
	}

	sort(v.begin(), v.end());

	cout << static_cast<int>(round(static_cast<double>(total) / N)) << "\n";
	cout << v[N / 2] << "\n";
	cout << Mode(v) << "\n";
	cout << v[v.size() - 1] - v[0] << "\n";

	return 0;
}