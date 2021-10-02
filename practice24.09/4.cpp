#include <iostream>

bool check_parity(int current_x) {
    return ~current_x & 1;
}

void swap_values(int& current_x, int& current_y) {
    current_x = current_x ^ current_y;  
    current_y = current_x ^ current_y;  
    current_x = current_x ^ current_y; 
}

int multiplyOnEight(int current_x) {
    return current_x << 3;
}

int main() {
    int x, y;
    std::cout << "Enter x and y:" << std::endl;
    std::cin >> x >> y;

    if (check_parity(x)) {
        std::cout << "х - четный" << std::endl;
    } else {
        std::cout << "х - нечетный" << std::endl;
    }
    if (check_parity(y)) {
        std::cout << "y - четный" << std::endl;
    } else {
        std::cout << "y - нечетный" << std::endl;
    }

    std::cout << "Значения поменялись местами" << std::endl;
    swap_values(x, y);

    std::cout << "Умножить х на 8:" << multiplyOnEight(x) << std::endl;
    std::cout << "Умножить y на 8:" << multiplyOnEight(y) << std::endl;
}