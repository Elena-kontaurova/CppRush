#include <iostream>      // для ввода/вывода (cin, cout)
#include <string>        // для работы со строками
#include <stack>         // для стеков (LIFO - Last In First Out)
#include <cmath>         // для математических функций
#include <iomanip>       // для форматирования вывода (setprecision)

using namespace std;     // чтобы не писать std:: перед каждой функцией

// Функция проверяет, является ли символ оператором
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Функция возвращает приоритет операций
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;  // низкий приоритет
    if (op == '*' || op == '/') return 2;  // высокий приоритет
    return 0;  // для скобок и других символов
}

// Функция выполняет математическую операцию над двумя числами
double calculate(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;  // сложение
    case '-': return a - b;  // вычитание
    case '*': return a * b;  // умножение
    case '/':
        if (b == 0) throw runtime_error("zero");  // проверка деления на 0
        return a / b;  // деление
    }
    return 0;  // если оператор не распознан
}

int main87() {
    string s;           // переменная для хранения входного выражения
    cin >> s;           // читаем выражение из консоли

    try {  // блок try-catch для обработки ошибок
        stack<double> numbers;  // стек для чисел
        stack<char> ops;        // стек для операторов и скобок

        // Проходим по каждому символу строки
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;  // пропускаем пробелы

            // Если текущий символ - цифра
            if (isdigit(s[i])) {
                string num;  // строка для сбора числа
                // Собираем все цифры числа (включая десятичную точку)
                while (i < s.length() && (isdigit(s[i]) || s[i] == '.')) {
                    num += s[i];  // добавляем символ к числу
                    i++;          // переходим к следующему символу
                }
                i--;  // возвращаемся на один символ назад
                numbers.push(stod(num));  // преобразуем строку в число и кладем в стек
            }
            // Если открывающая скобка
            else if (s[i] == '(') {
                ops.push('(');  // кладем скобку в стек операторов
            }
            // Если закрывающая скобка
            else if (s[i] == ')') {
                // Выполняем все операции до открывающей скобки
                while (!ops.empty() && ops.top() != '(') {
                    double b = numbers.top(); numbers.pop();  // берем второе число
                    double a = numbers.top(); numbers.pop();  // берем первое число
                    char op = ops.top(); ops.pop();           // берем оператор
                    numbers.push(calculate(a, b, op));        // вычисляем и кладем результат
                }
                if (!ops.empty()) ops.pop();  // убираем открывающую скобку из стека
            }
            // Если оператор (+, -, *, /)
            else if (isOperator(s[i])) {
                // Проверяем, является ли минус унарным (стоит в начале или после скобки/оператора)
                if (s[i] == '-' && (i == 0 || s[i - 1] == '(' || isOperator(s[i - 1]))) {
                    numbers.push(0);    // кладем 0 в стек чисел
                    ops.push('-');      // кладем оператор вычитания
                    continue;           // переходим к следующему символу
                }

                // Выполняем операции с высшим или равным приоритетом
                while (!ops.empty() && ops.top() != '(' &&
                    getPriority(ops.top()) >= getPriority(s[i])) {
                    double b = numbers.top(); numbers.pop();
                    double a = numbers.top(); numbers.pop();
                    char op = ops.top(); ops.pop();
                    numbers.push(calculate(a, b, op));
                }
                ops.push(s[i]);  // кладем текущий оператор в стек
            }
        }

        // Выполняем оставшиеся операции после обработки всей строки
        while (!ops.empty()) {
            double b = numbers.top(); numbers.pop();
            double a = numbers.top(); numbers.pop();
            char op = ops.top(); ops.pop();
            numbers.push(calculate(a, b, op));
        }

        // Проверяем корректность результата
        if (numbers.size() != 1) {
            cout << "Error.";  // должно остаться только одно число
        }
        else {
            double result = numbers.top();  // получаем результат
            // Проверяем на специальные значения (NaN, бесконечность)
            if (isnan(result) || isinf(result)) {
                cout << "Error.";
            }
            else {
                // Выводим результат с 6 знаками после запятой
                cout << fixed << setprecision(6) << result;
            }
        }
    }
    catch (...) {  // ловим любые исключения
        cout << "Error.";  // выводим сообщение об ошибке
    }

    return 0;  // завершаем программу
}