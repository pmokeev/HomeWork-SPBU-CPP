#include <iostream>

int bit_multiplying(unsigned int first_number, unsigned int second_number) {
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

int main() {
    int x, y;
    std::cout << "Enter x and y:" << std::endl;
    std::cin >> x >> y;

    std::cout << "x * y = " << bit_multiplying(x, y) << std::endl;

    return 0;
}