// �����: ������ �.�.

#pragma once
#include <iostream>
#include <sstream>
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
		top = stack.top();
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
			throw runtime_error("���������� ������������� � �����");
		}
	}

	/// <summary>
	/// ������� ������������
	/// </summary>
	/// <returns>
	/// ������ � ��������� ������������
	/// </returns>
	string HELP()
	{
		return "������� ������������:\n�����  �������� ����� � ����\n+, -, *, / �������������� ��������\nsin, cos, exp, log, sqrt �������\n = ������� ����� �� ������� �����\npop ������� ����� �� ������� �����\nclear �������� ����\n\n";
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
	/// ������ ������������ ������������, �������� � �������� ��������������� ��������� ������ ���� ��������� ���������
	/// </summary>
	/// <param name="linefull - ������ � �������������� ����������"></param>
	/// <returns>
	/// ����� ��������������� ���������
	/// </returns>
	double WORK(const string& linefull)
	{
		stringstream ss;
		string line;
		if (linefull.empty())
		{
			throw length_error("������ ������");
		}
		ss << linefull;
		while (!ss.eof())
		{
			ss >> line;

			if (isdigit(line[0]) || (line.size() > 1 && (line[0] == '-' || line[0] == '+') && isdigit(line[1]))) // ������� �����
			{
				PUSH(line);
			}
			else if (line == "+") // ������ ��������
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
				return top;
			}
			else if (line == "pop") // ������ ��������
			{
				POP();
			}
			else if (line == "clear") // ������ �������
			{
				CLEAR();
			}
		}
		return top;
	}
};

/// <summary>
/// ���� ������� ������������
/// </summary>
void test();