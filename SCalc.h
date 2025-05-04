// Автор: Игонин В.Ю.

#pragma once
#include <iostream>
#include <string>
#include "..\Stack\TStack.h"

using namespace std;

/// <summary>
/// Класс реализующий постфиксный калькулятор на основе стека
/// </summary>
class Calc
{
private:
	TemplateStack<double> stack; // Стек для калькулятора
public:

	double top = NULL;

	/// <summary>
	/// Показ вершины стека
	/// </summary>
	void SHOW()
	{
		if (!stack.isEmpty())
		{
			cout << "= " << stack.top() << endl;
			top = stack.top();
		}
		else
		{
			cout << "Стек пустой";
			top = NULL;
		}
	}

	/// <summary>
	/// Сложение 2 чисел в стеке
	/// </summary>
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

	/// <summary>
	/// Вычитание 2 чисел в стеке
	/// </summary>
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

	/// <summary>
	/// Умножение 2 чисел в стеке
	/// </summary>
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

	/// <summary>
	/// Деление 2 чисел в стеке
	/// </summary>
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

	/// <summary>
	/// Синус числа на вершине стека
	/// </summary>
	void SIN()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			top = NULL;
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(sin(x));
		SHOW();
	}

	/// <summary>
	/// Косинус числа на вершине стека
	/// </summary>
	void COS()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			top = NULL;
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(cos(x));
		SHOW();
	}

	/// <summary>
	/// Степень экспоненты числа на вершине стека
	/// </summary>
	void EXP()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			top = NULL;
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(exp(x));
		SHOW();
	}

	/// <summary>
	/// Натуральный логарифм числа на вершине стека
	/// </summary>
	void LOG()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			top = NULL;
			return;
		}
		double x = stack.top();
		if (x < 0)
		{
			cout << "Отрицательное число в логарифме\n";
			return;
		}
		stack.pop();
		stack.push(log(x));
		SHOW();
	}

	/// <summary>
	/// Корень числа на вершине стека
	/// </summary>
	void SQRT()
	{
		if (stack.isEmpty())
		{
			cout << "Стек пустой\n";
			top = NULL;
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

	/// <summary>
	/// Вставка числа в вершину стека
	/// </summary>
	/// <param name="line - вводимая строка"></param>
	void PUSH(const string& line)
	{
		try
		{
			double x = stod(line);
			stack.push(x);
			top = stack.top();
		}
		catch (exception e)
		{

		}
	}

	/// <summary>
	/// Справка калькулятора
	/// </summary>
	void HELP()
	{
		cout << "Команды калькулятора:\nЧисло  вставить число в стек\n+, -, *, / Арифметические операции\nsin, cos, exp, log, sqrt Функции\n = Вывести число на вершине стека\npop Удалить число на вершине стека\nclear Очистить стек\nquit Завершить работу\n\n";
	}

	/// <summary>
	/// Очистка стека
	/// </summary>
	void CLEAR()
	{
		stack.clear();
		top = NULL;
	}

	/// <summary>
	/// Удаление вершины стека
	/// </summary>
	void POP()
	{
		stack.pop();
		if (!stack.isEmpty())
		{
			top = stack.top();
		}
		else
		{
			top = NULL;
		}
	}

	/// <summary>
	/// Работа калькулятора
	/// </summary>
	void WORK()
	{
		HELP(); // вывод справки
		cout << "Введите выражение\n";
		while (true)
		{
			string line;
			cin >> line;
			if (line.size() == 0) // пользователь ничего не ввел
			{
				return;
			}

			if (line == "+") // запрос сложения
			{
				ADD();
			}
			else if (line == "-") // запрос вычитания
			{
				MINUS();
			}
			else if (line == "*") // запрос умножения
			{
				MULTIPLY();
			}
			else if (line == "/") // запрос деления
			{
				DIVISION();
			}
			else if (line == "sin") // запрос синуса
			{
				SIN();
			}
			else if (line == "cos") // запрос косинуса
			{
				COS();
			}
			else if (line == "exp") // запрос степени экспоненты
			{
				EXP();
			}
			else if (line == "log") // запрос натурального логарифма
			{
				LOG();
			}
			else if (line == "sqrt") // запрос корня
			{
				SQRT();
			}
			else if (line == "=") // запрос ответа
			{
				SHOW();
			}
			else if (isdigit(line[0]) || (line.size() > 1 && (line[0] == '-' || line[0] == '+') && isdigit(line[1]))) // введено число
			{
				PUSH(line);
			}
			else if (line == "pop") // запрос удаления
			{
				POP();
			}
			else if (line == "clear") // запрос очистка
			{
				CLEAR();
			}
			else if (line == "quit") // запрос завершения калькулятора
			{
				return;
			}
			else // вывод справки если не подходит
			{
				HELP();
			}
		}
	}
};

/// <summary>
/// Тест методов калькулятора
/// </summary>
void test();