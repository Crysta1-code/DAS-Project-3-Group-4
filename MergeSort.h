#pragma once
#include <cstddef>
#include <vector>

struct MergeSortStats {
    std::size_t comparisons = 0;
    std::size_t auxiliaryBytes = 0; // Peak temporary element buffer; excludes input and call stack.
};

MergeSortStats mergeSort(std::vector<int>& values);
