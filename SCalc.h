// �����: ������ �.�.

#pragma once
#include <iostream>
#include <string>
#include "..\Stack\TStack.h"

using namespace std;

/// <summary>
/// ����� ����������� ����������� ����������� �� ������ �����
/// </summary>
class Calc
{
private:
	TemplateStack<double> stack; // ���� ��� ������������
public:

	double top = NULL;

	/// <summary>
	/// ����� ������� �����
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
			cout << "���� ������";
			top = NULL;
		}
	}

	/// <summary>
	/// �������� 2 ����� � �����
	/// </summary>
	void ADD()
	{
		if (stack.getSize() < 2)
		{
			cout << "������� ����� < 2\n";
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
	/// ��������� 2 ����� � �����
	/// </summary>
	void MINUS()
	{
		if (stack.getSize() < 2)
		{
			cout << "������� ����� < 2\n";
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
	/// ��������� 2 ����� � �����
	/// </summary>
	void MULTIPLY()
	{
		if (stack.getSize() < 2)
		{
			cout << "������� ����� < 2\n";
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
	/// ������� 2 ����� � �����
	/// </summary>
	void DIVISION()
	{
		if (stack.getSize() < 2)
		{
			cout << "������� ����� < 2\n";
			return;
		}
		double x = stack.top();
		stack.pop();
		double y = stack.top();
		if (y == 0)
		{
			cout << "������ ������ �� 0";
			return;
		}
		stack.pop();
		stack.push(x / y);
		SHOW();
	}

	/// <summary>
	/// ����� ����� �� ������� �����
	/// </summary>
	void SIN()
	{
		if (stack.isEmpty())
		{
			cout << "���� ������\n";
			top = NULL;
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(sin(x));
		SHOW();
	}

	/// <summary>
	/// ������� ����� �� ������� �����
	/// </summary>
	void COS()
	{
		if (stack.isEmpty())
		{
			cout << "���� ������\n";
			top = NULL;
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(cos(x));
		SHOW();
	}

	/// <summary>
	/// ������� ���������� ����� �� ������� �����
	/// </summary>
	void EXP()
	{
		if (stack.isEmpty())
		{
			cout << "���� ������\n";
			top = NULL;
			return;
		}
		double x = stack.top();
		stack.pop();
		stack.push(exp(x));
		SHOW();
	}

	/// <summary>
	/// ����������� �������� ����� �� ������� �����
	/// </summary>
	void LOG()
	{
		if (stack.isEmpty())
		{
			cout << "���� ������\n";
			top = NULL;
			return;
		}
		double x = stack.top();
		if (x < 0)
		{
			cout << "������������� ����� � ���������\n";
			return;
		}
		stack.pop();
		stack.push(log(x));
		SHOW();
	}

	/// <summary>
	/// ������ ����� �� ������� �����
	/// </summary>
	void SQRT()
	{
		if (stack.isEmpty())
		{
			cout << "���� ������\n";
			top = NULL;
			return;
		}
		double x = stack.top();
		if (x < 0)
		{
			cout << "������������� ����� ��� ������\n";
			return;
		}
		stack.pop();
		stack.push(sqrt(x));
		SHOW();
	}

	/// <summary>
	/// ������� ����� � ������� �����
	/// </summary>
	/// <param name="line - �������� ������"></param>
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
	/// ������� ������������
	/// </summary>
	void HELP()
	{
		cout << "������� ������������:\n�����  �������� ����� � ����\n+, -, *, / �������������� ��������\nsin, cos, exp, log, sqrt �������\n = ������� ����� �� ������� �����\npop ������� ����� �� ������� �����\nclear �������� ����\nquit ��������� ������\n\n";
	}

	/// <summary>
	/// ������� �����
	/// </summary>
	void CLEAR()
	{
		stack.clear();
		top = NULL;
	}

	/// <summary>
	/// �������� ������� �����
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
	/// ������ ������������
	/// </summary>
	void WORK()
	{
		HELP(); // ����� �������
		cout << "������� ���������\n";
		while (true)
		{
			string line;
			cin >> line;
			if (line.size() == 0) // ������������ ������ �� ����
			{
				return;
			}

			if (line == "+") // ������ ��������
			{
				ADD();
			}
			else if (line == "-") // ������ ���������
			{
				MINUS();
			}
			else if (line == "*") // ������ ���������
			{
				MULTIPLY();
			}
			else if (line == "/") // ������ �������
			{
				DIVISION();
			}
			else if (line == "sin") // ������ ������
			{
				SIN();
			}
			else if (line == "cos") // ������ ��������
			{
				COS();
			}
			else if (line == "exp") // ������ ������� ����������
			{
				EXP();
			}
			else if (line == "log") // ������ ������������ ���������
			{
				LOG();
			}
			else if (line == "sqrt") // ������ �����
			{
				SQRT();
			}
			else if (line == "=") // ������ ������
			{
				SHOW();
			}
			else if (isdigit(line[0]) || (line.size() > 1 && (line[0] == '-' || line[0] == '+') && isdigit(line[1]))) // ������� �����
			{
				PUSH(line);
			}
			else if (line == "pop") // ������ ��������
			{
				POP();
			}
			else if (line == "clear") // ������ �������
			{
				CLEAR();
			}
			else if (line == "quit") // ������ ���������� ������������
			{
				return;
			}
			else // ����� ������� ���� �� ��������
			{
				HELP();
			}
		}
	}
};

/// <summary>
/// ���� ������� ������������
/// </summary>
void test();