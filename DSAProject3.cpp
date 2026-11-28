#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "Benchmark.h"
#include "DataSet.h"

namespace {

const std::string kCsvPath = "results.csv";
const int kDefaultTrials = 5;

int readInt(const std::string& prompt, int low, int high)
{
	while (true)
	{
		std::cout << prompt;
		int value;
		if (std::cin >> value && value >= low && value <= high)
			return value;
		if (std::cin.eof())
			std::exit(0);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a number from " << low << " to " << high << ".\n";
	}
}

void printRunSummary(const std::vector<RunResult>& results)
{
	for (const RunResult& r : results)
	{
		std::cout << r.algorithm << " trial " << r.trial << ": " << r.timeMs << " ms, "
			<< r.comparisons << " comparisons, "
			<< (r.sortedCorrectly ? "sorted correctly" : "NOT sorted correctly") << '\n';
	}
}

void saveResults(const std::vector<RunResult>& results, std::vector<RunResult>& sessionResults)
{
	sessionResults.insert(sessionResults.end(), results.begin(), results.end());
	if (appendToCsv(kCsvPath, results))
		std::cout << "Results appended to " << kCsvPath << "\n\n";
	else
		std::cout << "Could not write to " << kCsvPath << "\n\n";
}

void generateMenu(DataSet& data)
{
	std::cout << "\nSelect type of data set:\n";
	std::cout << "1: Random numbers\n";
	std::cout << "2: Random numbers with many duplicates\n";
	std::cout << "3: Ascending data\n";
	std::cout << "4: Descending data\n";
	std::cout << "0: Keep current data set\n";
	const int type = readInt("Enter choice: ", 0, 4);
	if (type == 0)
	{
		std::cout << "No changes made to data set\n\n";
		return;
	}

	std::cout << "\nSelect size:\n";
	std::cout << "1: 100,000\n2: 250,000\n3: 500,000\n";
	const int sizeChoice = readInt("Enter choice: ", 1, 3);
	const int sizes[] = { 100000, 250000, 500000 };
	const DataType types[] = { DataType::Random, DataType::ManyDuplicates, DataType::Ascending, DataType::Descending };

	data.generate(types[type - 1], sizes[sizeChoice - 1]);
	std::cout << "Data Set Generated: " << DataSet::typeName(data.getType())
		<< ", " << data.getSize() << " elements\n\n";
}

void runFullBenchmark(DataSet& data, std::vector<RunResult>& sessionResults)
{
	const int trials = readInt("Trials per algorithm per data set (1-20): ", 1, 20);
	const DataType types[] = { DataType::Random, DataType::ManyDuplicates, DataType::Ascending, DataType::Descending };
	const int sizes[] = { 100000, 250000, 500000 };

	std::vector<RunResult> all;
	for (DataType type : types)
	{
		for (int size : sizes)
		{
			std::cout << "Running " << DataSet::typeName(type) << ", " << size << " elements...\n";
			data.generate(type, size);
			auto merge = runTrials(Algorithm::MergeSort, data, trials);
			auto quick = runTrials(Algorithm::QuickSort, data, trials);
			all.insert(all.end(), merge.begin(), merge.end());
			all.insert(all.end(), quick.begin(), quick.end());
		}
	}
	std::cout << '\n';
	printResultsTable(all);
	saveResults(all, sessionResults);
}

} // namespace

int main() {
	DataSet data;
	std::vector<RunResult> sessionResults;

	while (true)
	{
		std::cout << "================================\n";
		std::cout << " SORTING PERFORMANCE ANALYZER\n";
		std::cout << "================================\n";
		std::cout << "1. Generate Dataset\n";
		std::cout << "2. Run Merge Sort\n";
		std::cout << "3. Run Quick Sort\n";
		std::cout << "4. Compare Algorithms\n";
		std::cout << "5. View Results\n";
		std::cout << "6. Run Full Benchmark (all data types and sizes)\n";
		std::cout << "0. Exit\n";
		if (data.getSize() > 0)
			std::cout << "Current data set: " << DataSet::typeName(data.getType()) << ", " << data.getSize() << " elements\n";

		const int option = readInt("\nEnter choice: ", 0, 6);

		if (option == 0)
			break;

		if (option == 1)
		{
			generateMenu(data);
		}
		else if (option == 5)
		{
			printResultsTable(sessionResults);
		}
		else if (option == 6)
		{
			runFullBenchmark(data, sessionResults);
		}
		else if (data.getSize() < 2)
		{
			std::cout << "No data set generated yet. Choose 1 first.\n\n";
		}
		else if (option == 2 || option == 3)
		{
			const Algorithm algorithm = (option == 2) ? Algorithm::MergeSort : Algorithm::QuickSort;
			auto results = runTrials(algorithm, data, 1);
			printRunSummary(results);
			saveResults(results, sessionResults);
		}
		else if (option == 4)
		{
			const int trials = readInt("Number of trials (1-20, default suggestion " + std::to_string(kDefaultTrials) + "): ", 1, 20);
			auto results = runTrials(Algorithm::MergeSort, data, trials);
			auto quick = runTrials(Algorithm::QuickSort, data, trials);
			results.insert(results.end(), quick.begin(), quick.end());
			printResultsTable(results);
			saveResults(results, sessionResults);
		}
	}

	return 0;
}
