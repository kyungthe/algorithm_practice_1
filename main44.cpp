/* https://www.acmicpc.net/problem/10845 Quiz */

#include <iostream>
#include <array>
#include <string>

using namespace std;


class MyQueue
{
public:
	MyQueue() : queue{ 0, }, size(0), current(0) {}

private:
	void Push(int n)
	{
		queue[size] = n;
		size++;
	}

	int Pop()
	{
		if (Empty())
			return -1;

		int result = queue[current];
		current++;

		return result;
	}

	int Size()
	{
		return size - current;
	}

	bool Empty()
	{
		return Size() == 0;
	}

	int Front()
	{
		if (Empty())
			return -1;

		return queue[current];
	}

	int Back()
	{
		if (Empty())
			return -1;

		return queue[size - 1];
	}

public:
	void Run(string inst, int n)
	{
		if (inst == "push") Push(n);
		else if (inst == "pop") cout << Pop() << "\n";
		else if (inst == "size") cout << Size() << "\n";
		else if (inst == "empty") cout << Empty() << "\n";
		else if (inst == "front") cout << Front() << "\n";
		else cout << Back() << "\n";
	}

private:
	array<int, 10001> queue;
	int size;
	int current;
};

int main()
{
	MyQueue myQueue;
	size_t N;
	string inst;

	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> inst;
		int num = 0;
		if (inst == "push")
			cin >> num;
		myQueue.Run(inst, num);
	}

	return 0;
}