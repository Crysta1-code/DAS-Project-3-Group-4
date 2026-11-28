#include "DataSet.h"
#include <algorithm>
#include <random>
#include <vector>

std::vector<int> DataSet::generate(DataType type, int size)
{
	dataSet.clear();
	sortedDataKey.clear();
	dataSet.reserve(size);
	currentType = type;

	std::random_device random;
	std::mt19937 gen(random());

	if (type == DataType::Random)
	{
		std::uniform_int_distribution<> range(-100000, 100000);
		for (int i = 0; i < size; i++)
			dataSet.push_back(range(gen));
	}
	else if (type == DataType::ManyDuplicates)
	{
		std::uniform_int_distribution<> range(-100, 100);
		for (int i = 0; i < size; i++)
			dataSet.push_back(range(gen));
	}
	else if (type == DataType::Ascending)
	{
		for (int i = 1; i <= size; i++)
			dataSet.push_back(i);
	}
	else
	{
		for (int i = size; i > 0; i--)
			dataSet.push_back(i);
	}

	sortedDataKey = dataSet;
	std::sort(sortedDataKey.begin(), sortedDataKey.end());

	return dataSet;
}

std::vector<int> DataSet::randomNumbers() { return generate(DataType::Random, 100000); }
std::vector<int> DataSet::randomNumbersMedium() { return generate(DataType::Random, 250000); }
std::vector<int> DataSet::randomNumbersLarge() { return generate(DataType::Random, 500000); }
std::vector<int> DataSet::manyDuplicates() { return generate(DataType::ManyDuplicates, 100000); }
std::vector<int> DataSet::manyDuplicatesMedium() { return generate(DataType::ManyDuplicates, 250000); }
std::vector<int> DataSet::manyDuplicatesLarge() { return generate(DataType::ManyDuplicates, 500000); }
std::vector<int> DataSet::alreadySorted() { return generate(DataType::Ascending, 500000); }
std::vector<int> DataSet::reverseSorted() { return generate(DataType::Descending, 500000); }

std::vector<int> DataSet::getDataSet()
{
	return dataSet;
}

std::vector<int> DataSet::getDataKey()
{
	return sortedDataKey;
}

DataType DataSet::getType() const
{
	return currentType;
}

std::size_t DataSet::getSize() const
{
	return dataSet.size();
}

std::string DataSet::typeName(DataType type)
{
	switch (type)
	{
	case DataType::Random: return "Random";
	case DataType::ManyDuplicates: return "Many Duplicates";
	case DataType::Ascending: return "Ascending";
	case DataType::Descending: return "Descending";
	}
	return "Unknown";
}
