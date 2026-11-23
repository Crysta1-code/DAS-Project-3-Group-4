#include "MergeSort.h"
#include <vector>
#include <cstddef>

namespace {
void sortRange(std::vector<int>& values, std::vector<int>& buffer,
               std::size_t left, std::size_t right, MergeSortStats& stats) {
    if (right - left <= 1) return;
    const std::size_t mid = left + (right - left) / 2;
    sortRange(values, buffer, left, mid, stats);
    sortRange(values, buffer, mid, right, stats);

    std::size_t i = left, j = mid, out = left;
    while (i < mid && j < right) {
        ++stats.comparisons;
        if (values[i] <= values[j]) buffer[out++] = values[i++];
        else buffer[out++] = values[j++];
    }
    while (i < mid) buffer[out++] = values[i++];
    while (j < right) buffer[out++] = values[j++];
    for (std::size_t k = left; k < right; ++k) values[k] = buffer[k];
}
} // namespace

MergeSortStats mergeSort(std::vector<int>& values) {
    MergeSortStats stats;
    if (values.size() < 2) return stats;
    std::vector<int> buffer(values.size());
    stats.auxiliaryBytes = buffer.size() * sizeof(int);
    sortRange(values, buffer, 0, values.size(), stats);
    return stats;
}
