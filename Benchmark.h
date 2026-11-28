#pragma once
#include <cstddef>
#include <string>
#include <vector>
#include "DataSet.h"

struct RunResult {
    std::string algorithm;
    std::string dataType;
    std::size_t size = 0;
    int trial = 0;
    double timeMs = 0.0;
    std::size_t comparisons = 0;
    std::size_t auxiliaryBytes = 0;
    bool sortedCorrectly = false;
};

enum class Algorithm { MergeSort, QuickSort };

RunResult runOnce(Algorithm algorithm, DataSet& data, int trial);

std::vector<RunResult> runTrials(Algorithm algorithm, DataSet& data, int trials);

bool appendToCsv(const std::string& path, const std::vector<RunResult>& results);

void printResultsTable(const std::vector<RunResult>& results);
