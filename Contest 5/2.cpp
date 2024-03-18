#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

int main()
{
    int M, N;
    std::cin >> M >> N;
    std::cin.ignore();

    std::string first_line;
    std::getline(std::cin, first_line);

    std::istringstream first_iss(first_line);
    std::string name1;
    first_iss >> name1;

    std::vector<int> numbers1(N);
    for (int& num: numbers1)
    {
        first_iss >> num;
    }

    int winner_score = std::numeric_limits<int>::min();
    std::vector<std::string> winners;

    for (int i = 1; i < M; ++i)
    {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string name;
        iss >> name;

        std::vector<int> numbers(N);
        for (int& num: numbers)
        {
            iss >> num;
        }

        int dot_product = 0;
        for (int j = 0; j < N; ++j)
        {
            dot_product += numbers1[j] * numbers[j];
        }

        if (dot_product > winner_score)
        {
            winner_score = dot_product;
            winners.clear();
            winners.push_back(name);
        }
        else if (dot_product == winner_score)
        {
            winners.push_back(name);
        }
    }

    for (const auto& winner: winners)
    {
        std::cout << winner << std::endl;
    }

    return 0;
}
