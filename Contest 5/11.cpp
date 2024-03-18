#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <deque>

int main() {
    int length, range, number;
    std::string numbers_str;
    std::cin >> length >> range;
    std::cin.ignore();
    std::getline(std::cin, numbers_str);
    std::vector<int> numbers;
    std::istringstream iss(numbers_str);

    while (iss >> number) {
        numbers.push_back(number);
    }
    std::deque<int> window;
    for (int i = 0; i < range; ++i) {
        while (!window.empty() && numbers[i] <= numbers[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
    }
    std::cout << numbers[window.front()] << std::endl;
    for (int i = range; i < length; ++i) {
        while (!window.empty() && window.front() <= i - range) {
            window.pop_front();
        }
        while (!window.empty() && numbers[i] <= numbers[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
        std::cout << numbers[window.front()] << std::endl;
    }

    return 0;
}
