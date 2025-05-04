#include "SCalc.h"
#include <cassert>

void test()
{
	Calc calc;
	// тесты сложения
	calc.PUSH("1");
	assert(calc.top == 1);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.ADD();
	assert(calc.top == 3);
	calc.POP();
	assert(calc.top == NULL);

	calc.PUSH("-1");
	assert(calc.top == -1);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.ADD();
	assert(calc.top == 1);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("-1");
	assert(calc.top == -1);
	calc.PUSH("-2");
	assert(calc.top == -2);
	calc.ADD();
	assert(calc.top == -3);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("1");
	assert(calc.top == 1);
	calc.PUSH("-2");
	assert(calc.top == -2);
	calc.ADD();
	assert(calc.top == -1);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("1");
	assert(calc.top == 1);
	calc.PUSH("");
	assert(calc.top == 1);
	calc.ADD();
	assert(calc.top == 1);
	calc.CLEAR();
	assert(calc.top == NULL);

	// тесты вычитания
	calc.PUSH("1");
	assert(calc.top == 1);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.MINUS();
	assert(calc.top == 1);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("-1");
	assert(calc.top == -1);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.MINUS();
	assert(calc.top == 3);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("1");
	assert(calc.top == 1);
	calc.PUSH("-2");
	assert(calc.top == -2);
	calc.MINUS();
	assert(calc.top == -3);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("-1");
	assert(calc.top == -1);
	calc.PUSH("-2");
	assert(calc.top == -2);
	calc.MINUS();
	assert(calc.top == -1);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("-1");
	assert(calc.top == -1);
	calc.PUSH("");
	assert(calc.top == -1);
	calc.MINUS();
	assert(calc.top == -1);
	calc.CLEAR();
	assert(calc.top == NULL);

	// тесты умножения
	calc.PUSH("4");
	assert(calc.top == 4);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.MULTIPLY();
	assert(calc.top == 8);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("-4");
	assert(calc.top == -4);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.MULTIPLY();
	assert(calc.top == -8);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("-4");
	assert(calc.top == -4);
	calc.PUSH("-2");
	assert(calc.top == -2);
	calc.MULTIPLY();
	assert(calc.top == 8);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("4");
	assert(calc.top == 4);
	calc.PUSH("-2");
	assert(calc.top == -2);
	calc.MULTIPLY();
	assert(calc.top == -8);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("0");
	assert(calc.top == 0);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.MULTIPLY();
	assert(calc.top == 0);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("-4");
	assert(calc.top == -4);
	calc.PUSH("");
	assert(calc.top == -4);
	calc.MULTIPLY();
	assert(calc.top == -4);
	calc.CLEAR();
	assert(calc.top == NULL);

	//тесты деления
	calc.PUSH("4");
	assert(calc.top == 4);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.DIVISION();
	assert(calc.top == 0.5);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("-4");
	assert(calc.top == -4);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.DIVISION();
	assert(calc.top == -0.5);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("4");
	assert(calc.top == 4);
	calc.PUSH("-2");
	assert(calc.top == -2);
	calc.DIVISION();
	assert(calc.top == -0.5);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("-4");
	assert(calc.top == -4);
	calc.PUSH("-2");
	assert(calc.top == -2);
	calc.DIVISION();
	assert(calc.top == 0.5);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("0");
	assert(calc.top == 0);
	calc.PUSH("2");
	assert(calc.top == 2);
	calc.DIVISION();
	assert(calc.top == 2); // делить на ноль нельзя поэтому деление не произойдет и стек не изменится
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("2");
	assert(calc.top == 2);
	calc.PUSH("0");
	assert(calc.top == 0);
	calc.DIVISION();
	assert(calc.top == 0);
	calc.CLEAR();
	assert(calc.top == NULL);

	calc.PUSH("2");
	assert(calc.top == 2);
	calc.PUSH("");
	assert(calc.top == 2);
	calc.DIVISION();
	assert(calc.top == 2);
	calc.CLEAR();
	assert(calc.top == NULL);

	//тесты косинуса
	calc.PUSH("4");
	assert(calc.top == 4);
	calc.COS();
	assert((fabs(calc.top) - 0.6536) < 0.0001);
	calc.CLEAR();

	calc.PUSH("");
	assert(calc.top == NULL);
	calc.COS();
	assert(calc.top == NULL);
	calc.CLEAR();

	//тесты синуса
	calc.PUSH("4");
	assert(calc.top == 4);
	calc.SIN();
	assert((fabs(calc.top) - 0.7568) < 0.0001);
	calc.CLEAR();

	calc.PUSH("");
	assert(calc.top == NULL);
	calc.SIN();
	assert(calc.top == NULL);
	calc.CLEAR();

	//тесты экспоненты
	calc.PUSH("4");
	assert(calc.top == 4);
	calc.EXP();
	assert((fabs(calc.top) - 54.5981) < 0.0001);
	calc.CLEAR();

	calc.PUSH("");
	assert(calc.top == NULL);
	calc.EXP();
	assert(calc.top == NULL);
	calc.CLEAR();

	//тесты натурального логарифма
	calc.PUSH("4");
	assert(calc.top == 4);
	calc.LOG();
	assert((fabs(calc.top) - 1.3862) < 0.0001);
	calc.CLEAR();

	calc.PUSH("");
	assert(calc.top == NULL);
	calc.LOG();
	assert(calc.top == NULL);
	calc.CLEAR();

	calc.PUSH("-4");
	assert(calc.top == -4);
	calc.LOG();
	assert(calc.top == -4); // отрицательное число, натуральный логарифм отрицательного числа не определен, стек не меняется
	calc.CLEAR();

	//тесты корня
	calc.PUSH("4");
	assert(calc.top == 4);
	calc.SQRT();
	assert(calc.top == 2);
	calc.CLEAR();

	calc.PUSH("");
	assert(calc.top == NULL);
	calc.SQRT();
	assert(calc.top == NULL);
	calc.CLEAR();

	calc.PUSH("-4");
	assert(calc.top == -4);
	calc.SQRT();
	assert(calc.top == -4); // отрицательное число, корень отрицательного числа не вычисляется без мнимых чисел, стек не меняется
	calc.CLEAR();

	//тесты показа вершины стека
	calc.PUSH("-4");
	assert(calc.top == -4);
	calc.PUSH("4");
	assert(calc.top == 4);
	calc.SHOW();
	assert(calc.top == 4);
	calc.POP();
	assert(calc.top == -4);
	calc.SHOW();
	assert(calc.top == -4);
	calc.POP();
	assert(calc.top == NULL);
	calc.SHOW();
	assert(calc.top == NULL);


}