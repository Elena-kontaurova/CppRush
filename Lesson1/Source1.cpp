#include <iostream>
#include <cmath>
using namespace std;

int main4() {
    long long N;
    cin >> N;

    long long M = 1;
    long long temp = N;

    // Перебираем возможные делители
    for (long long i = 2; i * i <= temp; i++) {
        int count = 0;
        while (temp % i == 0) {
            temp /= i;
            count++;
        }
        // Если степень нечётная, добавляем этот множитель в M
        if (count % 2 == 1) {
            M *= i;
        }
    }

    // Если остался простой множитель (больше 1)
    if (temp > 1) {
        M *= temp;
    }

    cout << M << endl;

    return 0;
}