#include <iostream>
#include <cmath>

int answer(int a, int S) {
    int h_osn = 2 * S / a;
    int b = std::sqrt(h_osn * h_osn + a / 2 * a / 2);
    return 2 * S / b;
}

int main() {
    int N;
    std::cin >> N;
    while (N--) {
        int a, S;
        std::cin >> a >> S;
        std::cout << "Answer = " << answer(a, S) << std::endl;
    }
}