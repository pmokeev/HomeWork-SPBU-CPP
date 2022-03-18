#include <iostream>
#include <utility>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <sstream>

using namespace std;

class Person {
private:
    string name, surname, birthDate;

public:
    Person(){}
    ~Person(){}

    Person(string personName) : name(std::move(personName)) {}
    Person(string personName, string personSurname) : name(std::move(personName)), surname(std::move(personSurname)) {}
    Person(string personName, string personSurname, string personBirthDate) : name(std::move(personName)), surname(std::move(personSurname)), birthDate(std::move(personBirthDate)) {}

    string getName();
    string getSurname();
    string getBirthDate();
    void printNameSurnameAge();
    void printBirthDateWeek();
};
