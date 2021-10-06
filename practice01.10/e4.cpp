#include <iostream>
#include <ctime>

void answer(int d, int m, int y) {
    int current_d = 1;
    int current_m = 10;
    int current_y = 2021;
    const int oneday = 0x15180;

    tm first_date = {0, 0, 0, d, m - 1, y - 0x76C, 0, 0, 0};
    tm second_Date = {0, 0, 0, current_d, current_m - 1, current_y - 0x76C, 0, 0, 0};

    time_t t1 = mktime(&first_date); 
    time_t t2 = mktime(&second_Date); 

    time_t diff = ((t1 > t2) ? t1 - t2 : t2 - t1) / oneday;

    std::cout << "\nРазница между двумя датами " << diff << " дней" << std::endl;
}

int main() {
    int d, m ,y;
    std::cin >> d >> m >> y;
    answer(d, m, y);
}