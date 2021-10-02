#include <iostream>

void derivative_sin(unsigned int current_n) {
    switch (current_n % 4)
    {
    case 0:
        std::cout << "sin(x)" << std::endl;
        break;
    case 1:
        std::cout << "cos(x)" << std::endl;
        break;
    case 2:
        std::cout << "-sin(x)" << std::endl;
        break;
    case 3:
        std::cout << "-cos(x)" << std::endl;
        break;
    }
}

int main() {
    unsigned int n;
    std::cout << "Enter n:" << std::endl;
    std::cin >> n;

    derivative_sin(n);

    return 0;
}