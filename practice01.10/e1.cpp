#include <iostream>

int answer(int N) {
    return N * (N - 1) / 2;
}

int main() {
    int N;
    std::cin >> N;

    while (N--) {
        int t;
        std::cin >> t;
        std::cout << "Answer = " << answer(t) << std::endl;
    }
}
