#include <iostream>

unsigned int greatest_common_divisor(unsigned int a, unsigned int b) {
  if (a % b == 0)
  {
    return b;
  }

  if (b % a == 0)
  {
    return a;
  }

  if (a > b)
  {
    return greatest_common_divisor(a%b, b);
  }

  return greatest_common_divisor(a, b%a);
}

bool answer(int v_1, int v_2, int v_3) {
    if(v_1 + v_2 < v_3)
    {
        return false;
    }

    if(v_1 == v_3 || v_2 == v_3 || v_1 + v_2 == v_3) {
        return true;
    }

    return v_3 % greatest_common_divisor(v_1, v_2) == 0;
}

int main() {
    int N;
    std::cin >> N;
    while (N--) {
        int v_1, v_2, v_3;
        std::cin >> v_1 >> v_2 >> v_3;

        std::cout << (answer(v_1, v_2, v_3) ? "Yes" : "No") << std::endl;
    }
    return 0;
}