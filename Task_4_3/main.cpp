#include <iostream>
#include "Person.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Person newPerson = Person("Иван", "Субботин", "16.03.1996");

    newPerson.printNameSurnameAge();
    newPerson.printBirthDateWeek();
    return 0;
}