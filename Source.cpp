#include <iostream>
#include <cstdint>

// Task 1

class Degree
{
private:
	int m_a;
	int m_b;
public:
	void set(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	void calculate()
	{
		double tmp = 1;
		for (int i = 0; i < m_b; i++)
		{
			tmp *= m_a;
		}
		printf("%d^(%d) = %6.2f\n", m_a, m_b, tmp);
	}
	Degree()
	{
		m_a = 5;
		m_b = 3;
	}

};

// Task 2

class RGBA
{
private:
	std::uint8_t m_red{ 0 }, m_green{ 0 }, m_blue{ 0 }, m_alpha{255};
public:
	RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
	{
		m_red = red;
		m_green = green;
		m_blue = blue;
		m_alpha = alpha;
	}

	void print()
	{
		printf("RED=%d | GREEN=%d | BLUE=%d | ALPHA=%d\n", m_red, m_green, m_blue, m_alpha);
	}
};

// Task 3

class Stack
{
private:
	enum { LENGTH = 10 };
	int32_t m_arr[LENGTH];
	uint8_t m_length{0};

public:
	void reset()
	{
		for (int i = 0; i < LENGTH; i++)
		{
			m_arr[i] = 0;
		}
		m_length = 0;
	}

	bool push(int32_t data)
	{
		if (m_length == LENGTH)
			return false;
		else
			m_arr[m_length++] = data;
		return true;
	}

	int32_t pop()
	{
		if (m_length == 0)
			printf("Stack is empty!\n");
		else
		{
			int32_t tmp = 0;
			tmp = m_arr[--m_length];
			m_arr[m_length] = 0;
			return tmp;
		}
		return 0;
	}

	void print()
	{
		printf("( ");
		for (int i = 0; i < m_length; i++)
			printf("%d ", m_arr[i]);
		printf(")\n");
	}
};

int main() {
	
	// Task 1
	Degree Dg;
	Dg.calculate();

	// Task 2
	RGBA rgba(16, 32, 64, 128);
	rgba.print();

	// Task 3
	Stack stack;
	/*for (int i = 0; i < 11; i++)
		if (stack.push(i))
			printf("OK\n");
	stack.print();
	
	printf("POP: ");
	for (int i = 0; i < 3; i++)
		printf("%d ", stack.pop());
	printf("\n");
	stack.push(18);
	stack.print();

	stack.reset();
	stack.print();
	stack.pop(); */

	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}