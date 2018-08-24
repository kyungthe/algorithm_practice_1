/* https://www.acmicpc.net/problem/11866 Quiz */\
/* 더 나은 방법 : https://www.acmicpc.net/source/9854184 */

#include <iostream>
#include <list>

using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;
	list<int> list;
	
	for (int i = 1; i <= N; i++)
		list.push_back(i);

	auto it = list.begin();
	for (int i = 0; i < M - 1; i++) it++;
	cout << "<";
	while (true)
	{
		cout << *it;
		it = list.erase(it);
		if (list.empty())
		{
			cout << ">";
			break;
		}
		else
		{
			cout << ", ";
		}
		if (it == list.end())
			it = list.begin();
		for (int i = 0; i < M - 1; i++)
		{
			it++;
			if (it == list.end())
				it = list.begin();
		}
	}

	return 0;
}