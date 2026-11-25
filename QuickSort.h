#pragma once
#include <cstddef>
#include <vector>

struct QuickSortStats {
    std::size_t comparisons = 0;
    std::size_t auxiliaryBytes = 0; // Peak temporary element buffer; excludes input and call stack.
};

QuickSortStats quickSortStats(std::vector<int>& dataSet);

void quickSort(std::vector<int>& unsotred, int low, int high, QuickSortStats& stats);
int partition(std::vector<int>& unsorted, int low, int high, QuickSortStats& stats);