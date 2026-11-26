#include "DataSet.h"
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

std::vector<int> DataSet::randomNumbers() 
{
	dataSet.clear();
	sortedDataKey.clear();

	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<> range(-100000, 100000);
	
	for (int i = 0; i < 100000; i++)
	{
		int number = range(gen);
		dataSet.push_back(number);
		sortedDataKey.push_back(number);
	}

	sort(sortedDataKey.begin(), sortedDataKey.end());

	return dataSet;
}

std::vector<int> DataSet::randomNumbersMedium()
{
	dataSet.clear();
	sortedDataKey.clear();

	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<> range(-100000, 100000);

	for (int i = 0; i < 250000; i++)
	{
		int number = range(gen);
		dataSet.push_back(number);
		sortedDataKey.push_back(number);
	}

	sort(sortedDataKey.begin(), sortedDataKey.end());

	return dataSet;

}

std::vector<int> DataSet::randomNumbersLarge()
{
	dataSet.clear();
	sortedDataKey.clear();

	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<> range(-100000, 100000);

	for (int i = 0; i < 500000; i++)
	{
		int number = range(gen);
		dataSet.push_back(number);
		sortedDataKey.push_back(number);
	}

	sort(sortedDataKey.begin(), sortedDataKey.end());

	return dataSet;
}

std::vector<int> DataSet::manyDuplicates()
{
	dataSet.clear();
	sortedDataKey.clear();

	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<> range(-100,100);

	for (int i = 0; i < 100000; i++)
	{
		int number = range(gen);
		dataSet.push_back(number);
		sortedDataKey.push_back(number);
	}

	sort(sortedDataKey.begin(), sortedDataKey.end());

	return dataSet;
}

std::vector<int> DataSet::manyDuplicatesMedium()
{
	dataSet.clear();
	sortedDataKey.clear();

	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<> range(-100, 100);

	for (int i = 0; i < 250000; i++)
	{
		int number = range(gen);
		dataSet.push_back(number);
		sortedDataKey.push_back(number);
	}

	sort(sortedDataKey.begin(), sortedDataKey.end());

	return dataSet;
}

std::vector<int> DataSet::manyDuplicatesLarge()
{
	dataSet.clear();
	sortedDataKey.clear();

	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<> range(-100, 100);

	for (int i = 0; i < 500000; i++)
	{
		int number = range(gen);
		dataSet.push_back(number);
		sortedDataKey.push_back(number);
	}

	sort(sortedDataKey.begin(), sortedDataKey.end());

	return dataSet;
}


std::vector<int> DataSet::alreadySorted()
{
	dataSet.clear();
	sortedDataKey.clear();

	for (int i = 1; i < 500001; i++)
	{
		dataSet.push_back(i);
		sortedDataKey.push_back(i);
	}

	sort(sortedDataKey.begin(), sortedDataKey.end());

	return dataSet;
}

std::vector<int> DataSet::reverseSorted()
{
	dataSet.clear();
	sortedDataKey.clear();

	for (int i = 500000; i> 0; i--)
	{
		dataSet.push_back(i);
		//std::cout << "Adding data to set: " <<i<<std::endl;
		sortedDataKey.push_back(i);
	}

	sort(sortedDataKey.begin(), sortedDataKey.end());

	return dataSet;
}


std::vector<int> DataSet::getDataSet()
{
	return dataSet;
}

std::vector<int> DataSet::getDataKey() 
{
	return sortedDataKey;
}
