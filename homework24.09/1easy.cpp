#include <iostream>

// Или просто:
// current_x ^ (1 << current_i)
int switch_bit(int current_x, int current_i) {
    int bit = (current_x & ( 1 << current_i )) >> current_i;

    if (bit) {
        current_x &= ~(1UL << current_i);
    } else {
        current_x |= 1 << current_i;
    }

    return current_x;
}

int main() {
    int x, i;
    std::cout << "Enter x and i:" << std::endl;
    std::cin >> x >> i;
    x = switch_bit(x, i);

    std::cout << "Новый x = " << x << std::endl;

    return 0;
}