#include <iostream>
#include <vector>
#include <ios>


int main(void) {
    std::ios_base::sync_with_stdio(false);
    size_t n;
    size_t m;
    std::cin >> n >> m;

    std::vector<int> numbers(n);
    for (auto &number : numbers) {
        std::cin >> number;
    }

    std::cout << std::endl;

    return 0;
}
