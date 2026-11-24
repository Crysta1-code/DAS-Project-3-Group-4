#include "MergeSort.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

void verify(std::vector<int> input) {
    auto expected = input;
    std::sort(expected.begin(), expected.end());
    const auto stats = mergeSort(input);
    assert(input == expected);
    if (input.size() > 1) assert(stats.auxiliaryBytes == input.size() * sizeof(int));
}

int main() {
    verify({});
    verify({42});
    verify({5, 4, 3, 2, 1});
    verify({1, 2, 3, 4, 5});
    verify({7, 7, 7, 7});
    verify({-5, 0, 9, -2, 9, 1});
    std::mt19937 rng(3530);
    std::uniform_int_distribution<int> dist(-10000, 10000);
    for (int size : {1000, 100000, 250000, 500000}) {
        std::vector<int> data(size);
        for (auto& x : data) x = dist(rng);
        verify(std::move(data));
        std::cout << "Passed " << size << " elements\n";
    }
    std::cout << "All Merge Sort tests passed.\n";
}
