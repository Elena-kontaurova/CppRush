#include <iostream>
#include <string>
using namespace std;

int main1() {
	setlocale(LC_ALL, "Russian");

	int age = 19;
	double height = 1.75;
	char grade = 'A';
	string name = "Lenok";
	bool isProgrammist = true;

	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Рост: " << height << endl;
	cout << "Оценка: " << grade << endl;
	cout << "Программист: " << isProgrammist << endl;

	return 0;
}