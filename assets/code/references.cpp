#include <cmath>
#include <iostream>
#include <vector>

// reference
void square(int& n) {
    n = pow(n, 2);
}

// copy
void _square(int n) {
    n = pow(n, 2);
}

// pass by reference
void shift(std::vector<std::pair<int, int>>& nums) {
    // Structured Binding
    for (auto& [first, second] : nums) {
        first++;
        second++;
    }
}

int main () {
    int num = 5;
    square(num);
    std::cout << num << std::endl;

    int num2 = 5;
    _square(num2);
    std::cout << num2 << std::endl;
    std::cout << '\n';

    std::vector<std::pair<int, int>> nums = {{1, 2}, {3, 4}, {5, 6}};
    shift(nums);
    for (auto& [first, second] : nums) {
        std::cout << first << " " << second << std::endl;
    }

    return 0;
}