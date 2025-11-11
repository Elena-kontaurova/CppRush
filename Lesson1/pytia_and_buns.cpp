#include <iostream>
using namespace std;

int main11() {
    int N, X, Y;
    cin >> N >> X >> Y;

    // ѕробуем разные комбинации булочек
    int min_need = N; // максимально возможна€ сумма, которую нужно зан€ть

    // ѕеребираем количество булочек первого вида
    for (int i = 0; i * X <= N; i++) { // пока стоимость i булочек не превышает денег ѕети
        // ƒл€ каждого количества булочек первого вида
        // вычисл€ем, сколько булочек второго вида можем купить
        int remaining = N - i * X;
        int j = remaining / Y;

        // —читаем, сколько денег осталось
        int change = remaining - j * Y;

        // ≈сли осталась сдача, значит нужно зан€ть деньги
        if (change > 0) {
            min_need = min(min_need, change);
        }
        else {
            // ≈сли сдачи нет, то ничего занимать не нужно
            min_need = 0;
            break;
        }
    }

    // ≈сли нашли способ купить без сдачи
    if (min_need == 0) {
        cout << 0 << endl;
    }
    else {
        cout << min_need << endl;
    }

    return 0;
}