#include "Person.h"

typedef std::chrono::system_clock Clock;

string Person::getName() {
    return this->name;
}

string Person::getSurname() {
    return this->surname;
}

string Person::getBirthDate() {
    return this->birthDate;
}

void Person::printNameSurnameAge() {
    int day, month, year;
    string tempString = this->birthDate;
    std::replace(tempString.begin(), tempString.end(), '.', ' ');
    istringstream is(tempString);
    is >> day;
    is >> month;
    is >> year;

    time_t temp = time(0);
    tm* time_now_temp = localtime(&temp);

    int age = time_now_temp->tm_year + 1900 - year;
    if (time_now_temp->tm_mon < month - 1) {
        age--;
    }
    cout << this->name << " " << this->surname << ": " << age << " полных лет\n";
}

void Person::printBirthDateWeek() {
    int day, month, year;
    string tempString = this->birthDate;
    std::replace(tempString.begin(), tempString.end(), '.', ' ');
    istringstream is(tempString);
    is >> day;
    is >> month;
    is >> year;

    tm time_in = { 0, 0, 0,
                        day, month, year - 1900 };

    time_t time_temp = std::mktime(&time_in);
    tm* time_out = localtime(&time_temp);

    cout << this->birthDate << ", ";
    switch (time_out->tm_wday) {
        case 0:
            cout << "воскресенье\n";
            break;
        case 1:
            cout << "понедельник\n";
            break;
        case 2:
            cout << "вторник\n";
            break;
        case 3:
            cout << "среда\n";
            break;
        case 4:
            cout << "четверг\n";
            break;
        case 5:
            cout << "пятница\n";
            break;
        case 6:
            cout << "суббота\n";
            break;
    }
}
