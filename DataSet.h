#pragma once
#include <vector>
class DataSet
{
	std::vector<int> dataSet;
	std::vector<int> sortedDataKey;

public:

	//Number generation functions
	std::vector<int> randomNumbers();
	std::vector<int> randomNumbersMedium();
	std::vector<int> randomNumbersLarge();
	std::vector<int> manyDuplicates();
	std::vector<int> manyDuplicatesMedium();
	std::vector<int> manyDuplicatesLarge();
	std::vector<int> alreadySorted();
	std::vector<int> reverseSorted();
	std::vector<int> getDataSet();
	std::vector<int> getDataKey();
	
};
