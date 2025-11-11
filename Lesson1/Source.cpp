#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main7() {
    int n, m, k;

    // Читаем количество веществ
    cin >> n;

    // Читаем количество реакций
    cin >> m;

    // Создаем словарь для реакций
    map<pair<int, int>, int> reactions;

    // Заполняем таблицу реакций
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // Сохраняем реакцию в обе стороны
        reactions[{a, b}] = c;
        reactions[{b, a}] = c;
    }

    // Читаем эксперимент
    cin >> k;
    vector<int> tube;

    for (int i = 0; i < k; i++) {
        int substance;
        cin >> substance;

        // Добавляем новое вещество в пробирку
        tube.push_back(substance);

        // Проверяем реакции пока возможно
        while (tube.size() > 1) {
            int top = tube.back();           // Верхнее вещество
            int below = tube[tube.size() - 2]; // Вещество под ним

            // Проверяем есть ли реакция между ними
            if (reactions.count({ top, below })) {
                // Есть реакция - получаем результат
                int result = reactions[{top, below}];
                // Удаляем два вещества
                tube.pop_back();
                tube.pop_back();
                // Добавляем результат реакции
                tube.push_back(result);
            }
            else {
                // Нет реакции - выходим из цикла
                break;
            }
        }
    }

    // Убираем одинаковые соседние вещества
    vector<int> answer;
    if (!tube.empty()) {
        answer.push_back(tube[0]);
        for (int i = 1; i < tube.size(); i++) {
            if (tube[i] != tube[i - 1]) {
                answer.push_back(tube[i]);
            }
        }
    }

    // Выводим ответ
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
        if (i != answer.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}