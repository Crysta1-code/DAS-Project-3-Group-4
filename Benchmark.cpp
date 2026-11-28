#include "Benchmark.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <tuple>

RunResult runOnce(Algorithm algorithm, DataSet& data, int trial)
{
    RunResult result;
    result.algorithm = (algorithm == Algorithm::MergeSort) ? "Merge Sort" : "Quick Sort";
    result.dataType = DataSet::typeName(data.getType());
    result.size = data.getSize();
    result.trial = trial;

    std::vector<int> values = data.getDataSet();

    const auto start = std::chrono::steady_clock::now();
    if (algorithm == Algorithm::MergeSort)
    {
        const MergeSortStats stats = mergeSort(values);
        result.comparisons = stats.comparisons;
        result.auxiliaryBytes = stats.auxiliaryBytes;
    }
    else
    {
        const QuickSortStats stats = quickSortStats(values);
        result.comparisons = stats.comparisons;
        result.auxiliaryBytes = stats.auxiliaryBytes;
    }
    const auto end = std::chrono::steady_clock::now();
    result.timeMs = std::chrono::duration<double, std::milli>(end - start).count();

    result.sortedCorrectly = (values == data.getDataKey());
    return result;
}

std::vector<RunResult> runTrials(Algorithm algorithm, DataSet& data, int trials)
{
    std::vector<RunResult> results;
    for (int t = 1; t <= trials; t++)
        results.push_back(runOnce(algorithm, data, t));
    return results;
}

bool appendToCsv(const std::string& path, const std::vector<RunResult>& results)
{
    bool needsHeader = true;
    {
        std::ifstream existing(path);
        if (existing && existing.peek() != std::ifstream::traits_type::eof())
            needsHeader = false;
    }

    std::ofstream out(path, std::ios::app);
    if (!out)
        return false;

    if (needsHeader)
        out << "algorithm,data_type,size,trial,time_ms,comparisons,auxiliary_bytes,sorted_correctly\n";

    for (const RunResult& r : results)
    {
        out << r.algorithm << ',' << r.dataType << ',' << r.size << ',' << r.trial << ','
            << std::fixed << std::setprecision(3) << r.timeMs << ','
            << r.comparisons << ',' << r.auxiliaryBytes << ','
            << (r.sortedCorrectly ? "yes" : "no") << '\n';
    }
    return true;
}

namespace {
std::string withCommas(std::size_t n)
{
    std::string s = std::to_string(n);
    for (int i = static_cast<int>(s.size()) - 3; i > 0; i -= 3)
        s.insert(static_cast<std::size_t>(i), ",");
    return s;
}
} // namespace

void printResultsTable(const std::vector<RunResult>& results)
{
    if (results.empty())
    {
        std::cout << "No results yet. Run a sort or a comparison first.\n\n";
        return;
    }

    struct Totals { double time = 0; double comparisons = 0; std::size_t bytes = 0; int count = 0; bool allCorrect = true; };
    std::map<std::tuple<std::string, std::size_t, std::string>, Totals> groups;
    for (const RunResult& r : results)
    {
        Totals& t = groups[std::make_tuple(r.dataType, r.size, r.algorithm)];
        t.time += r.timeMs;
        t.comparisons += static_cast<double>(r.comparisons);
        t.bytes = r.auxiliaryBytes;
        t.count++;
        t.allCorrect = t.allCorrect && r.sortedCorrectly;
    }

    std::cout << "================================================================================\n";
    std::cout << "                            PERFORMANCE RESULTS\n";
    std::cout << "================================================================================\n";
    std::cout << std::left << std::setw(17) << "Input Type" << std::setw(10) << "Size"
              << std::setw(12) << "Algorithm" << std::right << std::setw(7) << "Trials"
              << std::setw(13) << "Avg Time ms" << std::setw(15) << "Avg Compares"
              << std::setw(12) << "Aux Bytes" << "  Sorted\n";
    std::cout << "--------------------------------------------------------------------------------\n";

    bool everythingCorrect = true;
    for (const auto& entry : groups)
    {
        const std::string& type = std::get<0>(entry.first);
        const std::size_t size = std::get<1>(entry.first);
        const std::string& algorithm = std::get<2>(entry.first);
        const Totals& t = entry.second;
        everythingCorrect = everythingCorrect && t.allCorrect;
        std::cout << std::left << std::setw(17) << type << std::setw(10) << withCommas(size)
                  << std::setw(12) << algorithm << std::right << std::setw(7) << t.count
                  << std::setw(13) << std::fixed << std::setprecision(2) << t.time / t.count
                  << std::setw(15) << withCommas(static_cast<std::size_t>(t.comparisons / t.count + 0.5))
                  << std::setw(12) << withCommas(t.bytes)
                  << "  " << (t.allCorrect ? "yes" : "NO") << '\n';
    }
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << (everythingCorrect ? "All runs sorted correctly.\n"
                                    : "WARNING: at least one run did NOT sort correctly.\n");
    std::cout << "Aux Bytes = extra buffer memory only (excludes the input and recursion stack).\n\n";
}
