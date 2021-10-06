#include <iostream>

bool check(int r, int x, int y) {
    return x * x + y * y <= r * r;
}

int main() {
    int N;
    std::cin >> N;
    int counter = 0;
    while (N--) {
        int r;
        int t;
        std::cin >> r >> t;
        while (t--) {
            int x, y;
            std::cin >> x >> y;
            if (check(t, x, y)) {
                counter++;
            }
        }
    }

    std::cout << "Answer = " << counter << std::endl;
}