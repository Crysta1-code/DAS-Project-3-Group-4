/ DSAProject3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include "DataSet.h"
#include "MergeSort.h"
#include "QuickSort.h"

int main()
{
	DataSet unsortedData;
	std::vector<int> dataSet;

	while (true)
	{
		std::cout << "Select an option:" << std::endl;
		std::cout << "1: Generate New Data Set" << std::endl;
		std::cout << "2: Sort using QuickSort" << std::endl;
		std::cout << "3: Sort using MergeSort" << std::endl;
		std::cout << "0: Exit" << std::endl;

		int option;
		std::cin >> option;

		if (option == 1)
		{
			std::cout << "Select type of data set to sort:" << std::endl;
			std::cout << "1: Data set of 100,000 random numbers" << std::endl;
			std::cout << "2: Data set of 250,000 random numbers" << std::endl;
			std::cout << "3: Data set of 500,000 random numbers" << std::endl;
			std::cout << "4: Data set of 100,000 random numbers with many duplicates" << std::endl;
			std::cout << "5: Data set of 250,000 random numbers with many duplicates" << std::endl;
			std::cout << "6: Data set of 500,000 random numbers with many duplicates" << std::endl;
			std::cout << "7: Ascending data" << std::endl;
			std::cout << "8: Decending data" << std::endl;
			std::cout << "9: Keep current data set" << std::endl;

			int option2;
			std::cin >> option2;
			if (option2 == 1)
			{
				dataSet = unsortedData.randomNumbers();
				std::cout << "Data Set Generated" << std::endl;
				std::cout<<std::endl;

			}
			else if (option2 == 2)
			{;
				dataSet = unsortedData.randomNumbersMedium(); 
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option2 == 3)
			{
				dataSet = unsortedData.randomNumbersLarge();
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option2 == 4)
			{
				dataSet = unsortedData.manyDuplicates();
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option2 == 5)
			{
	
				dataSet = unsortedData.manyDuplicatesMedium();
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option2 == 6)
			{
				dataSet = unsortedData.manyDuplicatesLarge();
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option2 == 7)
			{
				dataSet = unsortedData.alreadySorted();
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option2 == 8)
			{
				dataSet = unsortedData.reverseSorted();
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option == 9)
			{
				std::cout << "No changes made to data set" << std::endl;
				std::cout << std::endl;
			}

		}
		else if(option==2 && dataSet.size()>1)
		{
			const auto stats=quickSortStats(dataSet);

			//Compare sorting algorithm to key
			std::vector<int> dataKey = unsortedData.getDataKey();
			bool flag = true;
			for (int i = 0; i < dataSet.size(); i++)
			{
				if (dataSet[i] != dataKey[i])
					flag = false;
					
				//std::cout << dataSet[i] << std::endl; //Testing
			}
			if (flag==true)
				std::cout << "Data sorted successfully using Quick Sort. Number of items sorted: " << dataSet.size() << std::endl;

		}
		else if (option == 2 && dataSet.size() < 1)
		{
			std::cout << "No data set generated yet" << std::endl;
		}
		else if (option == 3 && dataSet.size()>1)
		{
			const auto stats = mergeSort(dataSet);

			//Compare sorting algorithm to key
			std::vector<int> dataKey = unsortedData.getDataKey();
			bool flag = true;
			for (int i = 0; i < dataSet.size(); i++)
			{
				if (dataSet[i] != dataKey[i])
					flag = false;
					
				//std::cout << dataSet[i] << std::endl; //Testing
			}
			if (flag==true)
				std::cout << "Data sorted successfully using Merge Sort. Number of items sorted: " << dataSet.size() << std::endl;
			
		}
		else if (option == 3 && dataSet.size() < 1)
		{
			std::cout << "No data set generated yet" << std::endl;
		}
		else if (option == 0)
			break;
	}

}

