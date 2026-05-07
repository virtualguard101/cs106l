#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

using Iterator = std::vector<int>::iterator;

void IteratingByIndex(std::vector<int> vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
}

void IteratorByForEach(std::vector<int> vec) {
    for (auto& elem : vec) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

void IteratorByIterator(std::vector<int> vec) {
    // `it` is `std::vector<int>::iterator` type
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        // `++it` instead of `it++` avoids making unnecessary copies of the iterator
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

void ReadByInputIterator() {
    std::cout << "Enter numbers (Ctrl+D to stop): ";
    std::istream_iterator<int> start(std::cin); // start reading from `cin`
    std::istream_iterator<int> end; // default constructor = end of the stream
    std::vector<int> numbers(start, end);
}

void WriteByOutputIterator() {
    std::ostream_iterator<int> it(std::cout, ", ");
    for (int i = 0; i < 25; i+=5) {
        *it = i;
        ++it;
    }
    std::cout << '\n';
}

void WriteIntoVectorByOutputIterator(std::vector<int>& vec){
    // Equal to `vec.push_back(i)`
    std::back_insert_iterator<std::vector<int>> it(vec);
    for (int i = 0; i < 25; i+=5) {
        *it = i;
        ++it;
    }
}

int RandAccessIterator(std::vector<int>& vec, int index) {
    auto it = vec.begin();
    if (index < 0 || index >= vec.size()) {
        throw std::out_of_range("Index out of range");
    }
    return *(it + index);
}

void SortRandAccessIterable(std::vector<int>& vec) {
    // Only works for random access iterators (`std::vector`, `std::deque`)
    std::sort(vec.begin(), vec.end());
}

int main() {
    std::vector<int> vec{10, 20, 30, 40};
    std::cout << "[1] Iterate by index: ";
    IteratingByIndex(vec);

    std::cout << "[2] Iterate by range-for: ";
    IteratorByForEach(vec);

    std::cout << "[3] Iterate by iterator: ";
    IteratorByIterator(vec);

    std::cout << "[4] Write by output iterator: ";
    WriteByOutputIterator();

    std::vector<int> vec2{100};
    WriteIntoVectorByOutputIterator(vec2);
    std::cout << "[5] After back_insert_iterator write: ";
    IteratorByForEach(vec2);

    std::vector<int> unsorted{9, 1, 7, 3, 5};
    SortRandAccessIterable(unsorted);
    std::cout << "[6] After sort(random access): ";
    IteratorByForEach(unsorted);

    try {
        std::cout << "[7] RandAccessIterator(vec, 2): " << RandAccessIterator(vec, 2) << '\n';
        std::cout << "[8] RandAccessIterator(vec, 100): ";
        std::cout << RandAccessIterator(vec, 100) << '\n';
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }

    // Optional interactive demo:
    // ReadByInputIterator();

    return 0;
}
