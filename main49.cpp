/* https://www.acmicpc.net/problem/10866 Quiz */

#include <iostream>
#include <array>
#include <string>

using namespace std;

class MyDeque
{
public:
	MyDeque() : deque{ 0, }, size(0) {}

	void Run(string& inst, int n)
	{
		if (inst == "push_front") PushFront(n);
		else if (inst == "push_back") PushBack(n);
		else if (inst == "pop_front") cout << PopFront() << "\n";
		else if (inst == "pop_back") cout << PopBack() << "\n";
		else if (inst == "size") cout << Size() << "\n";
		else if (inst == "empty") cout << Empty() << "\n";
		else if (inst == "front") cout << Front() << "\n";
		else cout << Back() << "\n";
	}

	void Run(string& inst)
	{
		Run(inst, 0);
	}

private:
	void PushFront(int n)
	{
		for (int i = size; i > 0; i--)
			deque[i] = deque[i - 1];
		deque[0] = n;
		size++;
	}

	void PushBack(int n)
	{
		deque[size] = n;
		size++;
	}

	int PopFront()
	{
		if (size == 0)
			return -1;

		int result = deque[0];

		for (int i = 0; i < size; i++)
			deque[i] = deque[i + 1];
		size--;
		return result;
	}

	int PopBack()
	{
		if (size == 0)
			return -1;

		size--;
		return deque[size];
	}

	int Size()
	{
		return size;
	}

	int Empty()
	{
		return size == 0;
	}

	int Front()
	{
		if (Empty())
			return -1;

		return deque[0];
	}

	int Back()
	{
		if (Empty())
			return -1;

		return deque[size - 1];
	}
private:
	array<int, 10001> deque;
	int size;
};

int main()
{
	MyDeque deque;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string inst;
		cin >> inst;
		if (inst == "push_front" || inst == "push_back")
		{
			int n;
			cin >> n;
			deque.Run(inst, n);
		}
		else
			deque.Run(inst);
	}

	return 0;
}