// Автор: Игонин В.Ю.

#include <iostream>
#include "SCalc.h"
#include <clocale>

int main()
{
    test();
    system("cls");
    setlocale(LC_ALL, "rus");
    Calc calc;
    string line;
    cout << calc.HELP();
    getline(cin, line);
    cout << "= " << calc.WORK(line);
}
