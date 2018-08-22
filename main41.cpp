/* https://www.acmicpc.net/problem/10828 Quiz */

#include <iostream>
#include <array>
#include <string>

using namespace std;


class MyStack
{
public:
	MyStack() : stack{ 0, }, size(0) {}

private:
	void Push(int n)
	{
		stack[size] = n;
		size++;
	}

	int Pop()
	{
		if (size == 0)
			return -1;

		int result = stack[size - 1];
		size--;

		return result;
	}

	int Size()
	{
		return size;
	}

	bool Empty()
	{
		return size == 0;
	}

	int Top()
	{
		if (size == 0)
			return -1;

		return stack[size - 1];
	}

public:
	void Run(string inst, int n)
	{
		if (inst == "push") Push(n);
		else if (inst == "pop") cout << Pop() << "\n";
		else if (inst == "size") cout << Size() << "\n";
		else if (inst == "empty") cout << Empty() << "\n";
		else  cout << Top() << "\n";
	}

private:
	array<int, 10001> stack;
	int size;
};

int main()
{
	MyStack myStack;
	size_t N;
	string inst;
	int num;

	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> inst;
		int num = 0;
		if (inst == "push")
			cin >> num;
		myStack.Run(inst, num);
	}

	return 0;
}