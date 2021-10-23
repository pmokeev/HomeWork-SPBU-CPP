#include <iostream>
#include <cmath>

int plus(int x, int y) {
    return x + y;
} 

int minus(int x, int y) {
    return x - y;
}

int multiply(unsigned int first_number, unsigned int second_number) {
    int result = 0;

    while (second_number > 0)
    {
        if (second_number & 1)
        {
            int temp = first_number;
            while (temp != 0)
            {
                unsigned second_temp = result & temp;
                result = result ^ temp;
                temp = second_temp << 1;
            }
        }

        first_number = first_number << 1;
        second_number = second_number >> 1;
    }

    return result;
}

int division(int x, int y) {
    return x / y;
}

int mod(int x, int y) {
    return x % y;
}

int power(int x, unsigned int y)
{
    int pow = 1;
 
    while (y)
    {
        if (y & 1) {
            pow *= x;
        }
        y = y >> 1;
        x = x * x;
    }

    return pow;
}

int calculator(int x, int y, char current_operator) {
    switch (current_operator)
    {
    case '+':
        return plus(x, y);
    case '-':
        return minus(x, y);
    case '*':
        return multiply(x, y);
    case '/':
        if (y == 0) {
            std::cout << "Division by zero!\n";
            break;
        }
        return division(x, y);
    case '%':
        if (y == 0) {
            std::cout << "Division by zero!\n";
            break;
        }
        return mod(x, y);
    case '^':
        y = 1 << y;
        return power(x, y);
    default:
        std::cout << "Error operator value!\n";
        break;
    }
    return -1;
}

int main() {
    int x, y;
    char current_operator;
    std::cin >> x >> y >> current_operator;
    std::cout << calculator(x, y, current_operator);
}