#pragma once
#include <string>
#include <vector>

enum class DataType { Random, ManyDuplicates, Ascending, Descending };

class DataSet
{
	std::vector<int> dataSet;
	std::vector<int> sortedDataKey;
	DataType currentType = DataType::Random;

public:

	std::vector<int> generate(DataType type, int size);

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

	DataType getType() const;
	std::size_t getSize() const;
	static std::string typeName(DataType type);
};
