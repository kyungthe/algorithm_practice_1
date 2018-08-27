/* https://www.acmicpc.net/problem/5430 Quiz */

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string func;
		int n;
		cin >> func >> n;

		int deleteCount = 0;
		for (int j = 0; j < func.size(); j++)
			if (func[j] == 'D')
				deleteCount++;

		deque<int> deque;
		string str, num;
		cin >> str;

		if (deleteCount > n)
		{
			cout << "error" << "\n";
			continue;
		}

		for (char c : str)
		{
			if (c == ',' || c == ']' && num.size() > 0)
			{
				deque.push_back(stoi(num));
				num = "";
			}
			else if ('0' <= c && c <= '9')
				num += c;
		}

		int reverseCount = 0;
		for (char c : func)
		{
			if (c == 'R')
				reverseCount++;
			else if(reverseCount % 2)
				deque.pop_back();
			else
				deque.pop_front();
		}
		if (reverseCount % 2)
			reverse(deque.begin(), deque.end());

		cout << "[";
		if (!deque.empty())
		{
			for (int i = 0; i < deque.size() - 1; i++)
				cout << deque[i] << ",";
			cout << deque[deque.size() - 1];
		}
		cout << "]\n";
	}

	return 0;
}