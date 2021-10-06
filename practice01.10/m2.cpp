#include <iostream>
#include <functional>
#include <string>

void for_loop(int start_value, int end_value, bool right_border, std::string counter_action, std::function<void()> action) {
    int iterator = start_value;
start_loop:
    if (counter_action == "++") {
        if (right_border) {
            if (iterator <= end_value) {
                iterator++;
                action();
                goto start_loop;
            } 
            else {
                return;
            }
        }
        else {
            if (iterator < end_value) {
                iterator++;
                action();
                goto start_loop;
            } 
            else {
                return;
            }
        }
    }
    else if (counter_action == "--")
    {
        if (right_border) {
            if (iterator >= end_value) {
                iterator++;
                action();
                goto start_loop;
            } 
            else {
                return;
            }
        }
        else {
            if (iterator > end_value) {
                iterator++;
                action();
                goto start_loop;
            } 
            else {
                return;
            }
        }
    }
}

void while_loop(std::function<bool()> condition, std::function<void()> action) {
start_loop:
    if (condition()) {
        action();
        goto start_loop;
    }
}

void do_while_loop(std::function<bool()> condition, std::function<void()> action) {
    action();
start_loop:
    if (condition()) {
        action();
        goto start_loop;
    }
}

int main() {
    int iterator123 = 0;

    for_loop(0, 10, false, "++", [&]() { iterator123++; std::cout << iterator123 << std::endl; });

    iterator123 = 0;
    while_loop([&]() -> bool { return iterator123 < 10; }, [&]() { iterator123++; std::cout << iterator123 << std::endl; });

    iterator123 = 0;
    do_while_loop([&]() -> bool { return iterator123 < 0; }, [&]() { iterator123++; std::cout << iterator123 << std::endl; });
    
    return 0;
}