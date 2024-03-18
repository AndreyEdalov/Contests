#include <iostream>
#include <vector>
#include <set>


int main()
{
    int length, range, m;
    std::cin >> length >> range;
    std::vector<int> numbers;
    for (int i = 0; i < length; i++)
    {
        std::cin >> m;
        numbers.push_back(m);
    }
    std::multiset<int> window(numbers.begin(), numbers.begin() + range);
    std::cout << *window.begin() << '\n';
    for (int j = range; j < length; j++)
    {
        window.erase(window.lower_bound(numbers[j - range]));
        window.insert(numbers[j]);
        std::cout << *window.begin() << "\n";
    }
    return 0;
}
