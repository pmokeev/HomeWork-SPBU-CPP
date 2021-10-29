#include <iostream>

using namespace std;

int count_of_inversion_in_array(int* array, int size) {
    int counter = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[i]) {
                counter++;
            }
        }
    }
    
    return counter;
}

bool test_case1() {
    int array_size = 4;
    int* array = new int[array_size];
    array[0] = 4;
    array[1] = 3;
    array[2] = 2;
    array[3] = 1;
    return !(6 == count_of_inversion_in_array(array, array_size));
}

bool test_case2() {
    int array_size = 4;
    int* array = new int[array_size];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    return !(0 == count_of_inversion_in_array(array, array_size));
}

int main() {
    if (test_case1() && test_case2()) {
        cout << "Failed on tests!";
        return 1;
    }

    int array_size;
    cin >> array_size;
    int* array = new int[array_size];
    for (int i = 0; i < array_size; i++)
    {
        cin >> array[i];
    }

    cout << count_of_inversion_in_array(array, array_size);

    delete [] array;
    return 0;
}