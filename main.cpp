#include <iostream>
#include "subset_iterator.h"

void print(std::vector<int>&& subset)
{
    std::cout << "{ ";
    for (const auto& item : subset) {
        std::cout << item << " ";
    }
    std::cout << "}\n";
}

int main()
{
    std::vector<double> zrlam{ 1, 2, 3, 4, 5 };
    std::subset_iterator<int> iter(zrlam.begin(), zrlam.end());
    while (!iter.is_end()) {
        print(*iter);
        ++iter;
    }
}
