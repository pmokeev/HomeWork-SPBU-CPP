#include <iostream>

void calculate_path(float current_t, float current_v, float& S_1, float& S_2, float& S) {
    S_1 = current_t * current_v;
    S_2 = current_t * current_v / 2;
    S = S_1 + S_2;
}

int main() {
    float t, v;
    std::cout << "Enter t and v:" << std::endl;
    std::cin >> t >> v;
    float S_1, S_2, S;

    calculate_path(t, v, S_1, S_2, S);

    std::cout << "Путь до торможения = " << S_1 << std::endl;
    std::cout << "Путь во время торможения = " << S_2 << std::endl;
    std::cout << "Общий путь = " << S << std::endl;

    return 0;
}