#include <iostream>

int set_i_bit(int current_x, int current_i) {
    current_x |= 1 << current_i;

    return current_x;
}

int main() { 
    int x, i;
    std::cout << "Enter x:" << std::endl;
    std::cin >> x;
    std::cout << "Enter i:" << std::endl;
    std::cin >> i;

    x = set_i_bit(x, i);
    std::cout << "Result = " << x << std::endl;
    return 0;
}