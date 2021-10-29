#include <iostream>
#include <string>

using namespace std;

string get_binary_string_of_int(int x){
    string result = "";
    while (x > 0) {
        result = to_string(x%2) + result;
        x /= 2;
    }

    return result;
}

bool check_of_palindrome_in_binary(int number) {
    string binary_string = get_binary_string_of_int(number);
    for (int i = 0; i < binary_string.size(); i++)
    {
        if (binary_string[i] != binary_string[binary_string.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool test_case1() {
    return !check_of_palindrome_in_binary(3);
}

bool test_case2() {
    return check_of_palindrome_in_binary(2);
}

bool test_case3() {
    return !check_of_palindrome_in_binary(5);
}

int main() {
    if (test_case1() && test_case2() && test_case3()) {
        cout << "Failed on tests!";
        return 1;
    }

    int number;
    cin >> number;
    if (check_of_palindrome_in_binary(number)) {
        cout << "Число в двоичном представлении - палиндром";
    } else {
        cout << "Число в двоичном представлении - не палиндром";
    }

    return 0;
}