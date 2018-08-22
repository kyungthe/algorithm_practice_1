/* https://www.acmicpc.net/problem/1874 Quiz */

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	stack<int> stack;
	vector<int> sequence(100001,0);
	string result;
	int current = 1;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> sequence[i];

	stack.push(-1);		// 스택이 비어있지 않도록 하기 위한 더미데이터
	for (int i = 0; i < N;)
	{
		if (sequence[i] > stack.top())
		{
			while (current <= sequence[i])
			{
				stack.push(current);
				current++;
				result += "+\n";
			}
		}
		else if (sequence[i] == stack.top())
		{
			stack.pop();
			result += "-\n";
			i++;
		}
		else
		{
			result = "NO";
			break;
		}
	}

	cout << result << "\n";

	return 0;
}