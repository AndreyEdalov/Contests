#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    int length, range;
    std::string numbers_str;
    std::cin >> length >> range; // Assuming range might be used for validation or other purposes later
    std::cin.ignore(); // To ignore the newline character after reading range
    std::getline(std::cin, numbers_str); // Read the entire line of numbers as a string

    std::vector<int> numbers;
    std::istringstream iss(numbers_str);

    int number;
    while (iss >> number) {
        numbers.push_back(number);
    }

    // Optionally, you might want to check if the numbers read match 'length' and perform any operations based on 'range'

    // Printing the numbers stored in the vector
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
