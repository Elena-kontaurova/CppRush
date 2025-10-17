#include <iostream>
#include <windows.h>

using namespace std;

int main5() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	double a, b;
	cout << "Введите первое число: ";
	cin >> a;

	cout << "Введите второе число: ";
	cin >> b;

	cout << a << "+" << b << "=" << a + b << endl;
	cout << a << "-" << b << "=" << a - b << endl;
	cout << a << "*" << b << "=" << a * b << endl;
	if (b != 0) {
		cout << a << "/" << b << "=" << a / b << endl;
	}
	else {
		cout << "На ноль делить нельзя! " << endl;
	}

	return 0;
}