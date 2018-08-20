/* https://www.acmicpc.net/problem/2108 Quiz */

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

int Mode(vector<int>& v)
{
	array<int, 8001> arr = { 0 };
	int max1, max2;

	max1 = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		int index = v[i] + 4000;
		arr[index]++;
		if (arr[index] > arr[max1])
			max1 = index;
	}

	max2 = 0;
	for (size_t i = 0; i < arr.max_size(); i++)
		if (i != max1 && arr[i] > arr[max2])
			max2 = i;

	if (arr[max1] == arr[max2])
		return max2 - 4000;
	else
		return max1 - 4000;
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