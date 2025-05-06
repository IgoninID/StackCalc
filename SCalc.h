// Автор: Игонин В.Ю.

#pragma once
#include <iostream>
#include <sstream>
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
			throw runtime_error("Невозможно преобразовать в число");
		}
	}

	/// <summary>
	/// Справка калькулятора
	/// </summary>
	/// <returns>
	/// Строка с командами калькулятора
	/// </returns>
	string HELP()
	{
		return "Команды калькулятора:\nЧисло  вставить число в стек\n+, -, *, / Арифметические операции\nsin, cos, exp, log, sqrt Функции\n = Вывести число на вершине стека\npop Удалить число на вершине стека\nclear Очистить стек\n\n";
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
	/// Работа постфиксного калькулятора, элементы и операции математического выражения должны быть разделены пробелами
	/// </summary>
	/// <param name="linefull - строка с математическим выражением"></param>
	/// <returns>
	/// Ответ математического выражения
	/// </returns>
	double WORK(const string& linefull)
	{
		stringstream ss;
		string line;
		if (linefull.empty())
		{
			throw length_error("Пустая строка");
		}
		ss << linefull;
		while (!ss.eof())
		{
			ss >> line;

			if (isdigit(line[0]) || (line.size() > 1 && (line[0] == '-' || line[0] == '+') && isdigit(line[1]))) // введено число
			{
				PUSH(line);
			}
			else if (line == "+") // запрос сложения
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
				return top;
			}
			else if (line == "pop") // запрос удаления
			{
				POP();
			}
			else if (line == "clear") // запрос очистка
			{
				CLEAR();
			}
		}
		return top;
	}
};

/// <summary>
/// Тест методов калькулятора
/// </summary>
void test();