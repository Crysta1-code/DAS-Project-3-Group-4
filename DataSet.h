#pragma once
#include <vector>
class DataSet
{
	std::vector<int> dataSet;
	std::vector<int> sortedDataKey;

public:

	//Number generation functions
	std::vector<int> randomNumbers(int maxNumber);
	std::vector<int> randomNumbersLarge(int maxNumber);
	std::vector<int> alreadySorted();
	std::vector<int> reverseSorted();
	std::vector<int> sameNumber(int userNumber);

	

};

