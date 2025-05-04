#pragma once
#include <iostream>
#include <string>
#include "..\Stack\TStack.h"

using namespace std;

class Calc
{
private:
	TemplateStack<double> stack;
public:
	void SHOW()
	{
		if (!stack.isEmpty())
		{
			cout << "= " << stack.top() << endl;
		}
		else
		{
			cout << "Стек пустой";
		}
	}

	void ADD()
	{
		if (stack.getSize() < 2)
		{
			cout << "Глубина стека < 2\n";
			return;
		}
		double x = stack.top();
		stack.pop();
		double y = stack.top();
		stack.pop();
		stack.push(x + y);
		SHOW();
	}

	void MINUS()
	{
		if (stack.getSize() < 2)
		{
			cout << "Глубина стека < 2\n";
			return;
		}
		double x = stack.top();
		stack.pop();
		double y = stack.top();
		stack.pop();
		stack.push(x - y);
		SHOW();
	}

	void MULTIPLY()
	{
		if (stack.getSize() < 2)
		{
			cout << "Глубина стека < 2\n";
			return;
		}
		double x = stack.top();
		stack.pop();
		double y = stack.top();
		stack.pop();
		stack.push(x * y);
		SHOW();
	}

	void DIVISION()
	{
		if (stack.getSize() < 2)
		{
			cout << "Глубина стека < 2\n";
			return;
		}
		double x = stack.top();
		stack.pop();
		double y = stack.top();
		if (y == 0)
		{
			cout << "Нельзя делить на 0";
			return;
		}
		stack.pop();
		stack.push(x / y);
		SHOW();
	}

	void SIN()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(sin(x));
		SHOW();
	}

	void COS()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(cos(x));
		SHOW();
	}

	void EXP()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(exp(x));
		SHOW();
	}

	void LOG()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(log(x));
		SHOW();
	}

	void SQRT()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			return;
		}
		double x = stack.top();
		if (x < 0)
		{
			cout << "Отрицательное число под корнем\n";
			return;
		}
		stack.pop();
		stack.push(sqrt(x));
		SHOW();
	}

	void PUSH(const string& line)
	{
		double x = stod(line);
		stack.push(x);
	}

	void HELP()
	{
		cout << "Команды калькулятора:\nЧисло  вставить число в стек\n+, -, *, / Арифметические операции\nsin, cos, exp, log, sqrt Функции\n = Вывести число на вершине стека\npop Удалить число на вершине стека\nclear Очистить стек\nquit Завершить работу\n";
	}

	void CLEAR()
	{
		stack.clear();
	}

	void POP()
	{
		stack.pop();
	}

	void WORK()
	{
		HELP();
		cout << "Введите выражение\n";
		while (true)
		{
			string line;
			cin >> line;
			if (line.size() == 0)
			{
				return;
			}

			if (line == "+")
			{
				ADD();
			}
			else if (line == "-")
			{
				MINUS();
			}
			else if (line == "*")
			{
				MULTIPLY();
			}
			else if (line == "/")
			{
				DIVISION();
			}
			else if (line == "sin")
			{
				SIN();
			}
			else if (line == "cos")
			{
				COS();
			}
			else if (line == "exp")
			{
				EXP();
			}
			else if (line == "log")
			{
				LOG();
			}
			else if (line == "sqrt")
			{
				SQRT();
			}
			else if (line == "=")
			{
				SHOW();
			}
			else if (isdigit(line[0]) || (line.size() > 1 && (line[0] == '-' || line[0] == '+') && isdigit(line[1])))
			{
				PUSH(line);
			}
			else if (line == "pop")
			{
				POP();
			}
			else if (line == "clear")
			{
				CLEAR();
			}
			else if (line == "quit")
			{
				return;
			}
			else
			{
				HELP();
			}
		}
	}
};

void test();