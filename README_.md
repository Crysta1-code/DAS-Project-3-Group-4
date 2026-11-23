# Merge Sort Module

Files: `MergeSort.h`, `MergeSort.cpp`, `test_merge_sort.cpp`.

## Compile and test

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic MergeSort.cpp test_merge_sort.cpp -o test_merge_sort
./test_merge_sort
```

## Integration into existing DSAProject3.cpp

Add `#include "MergeSort.h"` and a menu choice for Merge Sort. For example, after generating a dataset:

```cpp
std::vector<int> mergeInput = dataSet; // preserve original for fair comparisons
MergeSortStats stats = mergeSort(mergeInput);
std::cout << "Comparisons: " << stats.comparisons << '\n';
std::cout << "Temporary buffer bytes: " << stats.auxiliaryBytes << '\n';
```

For fair timing comparisons, copy the same original dataset for each algorithm **before** starting its timer. The `auxiliaryBytes` field reports only the peak allocated integer buffer, not the call stack or all process memory. Benchmarking, CSV output, and charting are intentionally left to Katie.
