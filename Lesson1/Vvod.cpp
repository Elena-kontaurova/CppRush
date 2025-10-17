#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main2() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	string userName;
	int userAge;
	int favoritNumber;

	cout << "Как тебя зовут? ";
	cin >> userName;

	cout << "Сколько тебе лет? ";
	cin >> userAge;

	cout << "Назови свое любимое число? ";
	cin >> favoritNumber;

	cout << "------ Твоя анкета ------" << endl;
	cout << "Тебя зовут: " << userName << endl;
	cout << "Тебе " << userAge << " лет." << endl;
	cout << "Твое любимое число: " << favoritNumber << endl;
	cout << "Через год тебе будет: " << userAge + 1 << endl;

	return 0;
}