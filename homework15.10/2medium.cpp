#include <iostream>

using namespace std;

void generate_values(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = rand() % 41 + 10;
        }
    }
}

void print_array(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int rows = 4;
    int columns = 4;
    int** array = new int*[rows];

    for(int i = 0; i < rows; i++){
        array[i] = new int[columns];
    }

    generate_values(array, rows, columns);
    print_array(array, rows, columns);

    delete [] array;
    return 0;
}