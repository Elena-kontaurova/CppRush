#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main9() {
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int voda;
        cin >> voda;
        if (voda == 0) {
            cout << "0" << endl;
            continue;
        }
        string result = "";
        int ki = voda;
        while (ki != 0) {
            int abc = ki % 3;
            if (abc == 2) {
                result += "i";
                ki = ki / 3 + 1;
            }
            else if (abc == -1) {
                result += "i";
                ki = ki / 3;
            }
            else if (abc == -2) {
                result += "1";
                ki = ki / 3 - 1;
            }
            else {
                result += to_string(abc);
                ki = ki / 3;
            }
        }
        reverse(result.begin(), result.end());
        cout << result << endl;
    }
    cout << endl;
    return 0;
}