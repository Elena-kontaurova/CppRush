#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Stack {
    char info;
    Stack* next;
};

void push(Stack*& t, char elem) {
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->info = elem;
    p->next = t;
    t = p;
}

char pop(Stack*& t) {
    if (t == nullptr) return '\0';
    char temp = t->info;
    Stack* temp_ptr = t;
    t = t->next;
    free(temp_ptr);
    return temp;
}

int prior(char s) {
    if (s == '(') return 0;
    if (s == ')') return -1;
    if (s == '+' || s == '-') return 1;
    if (s == '*' || s == '/') return 2;
    return -1;
}

int main12343() {
    Stack* top1 = nullptr;
    Stack* top2 = nullptr;
    string s;
    cin >> s;
    vector<char> d;

    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z') {
            push(top1, s[i]);
        }
        else if (s[i] == '(') {
            push(top2, '(');
        }
        else if (s[i] == ')') {
            while (top2 != nullptr && top2->info != '(') {
                push(top1, pop(top2));
            }
            if (top2 != nullptr) pop(top2);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            while (top2 != nullptr && prior(s[i]) <= prior(top2->info)) {
                push(top1, pop(top2));
            }
            push(top2, s[i]);
        }
    }

    while (top2 != nullptr) {
        push(top1, pop(top2));
    }

    while (top1 != nullptr) {
        d.push_back(pop(top1));
    }

    for (int i = d.size() - 1; i >= 0; i--) {
        cout << d[i];
    }
    cout << endl;

    return 0;
}