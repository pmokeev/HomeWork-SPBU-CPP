#include <iostream>

using namespace std;

int get_single_number() {
    int resultNumber = 0;
    int number = 0;
    // Для того, чтобы ввод закончился - необходимо прожать Ctrl+D
    while (cin >> number) {
        resultNumber ^= number;
    }
    return resultNumber;
}

int main() {
    cout << get_single_number();
    return 0;
}