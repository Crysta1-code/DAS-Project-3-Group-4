// DSAProject3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "DataSet.h"

void quickSort(std::vector<int>& unsotred, int low, int high);
int partition(std::vector<int>& unsorted, int low, int high);


int main()
{
	DataSet unsortedData;
	std::vector<int> dataSet;

	while (true)
	{
		std::cout << "Select an option:" << std::endl;
		std::cout << "1: Generate New Data Set" << std::endl;
		std::cout << "2: Sort using QuickSort" << std::endl;
		std::cout << "0: Exit" << std::endl;

		int option;
		std::cin >> option;

		if (option == 1)
		{
			std::cout << "Select type of data set to sort:" << std::endl;
			std::cout << "1: Data set of random numbers" << std::endl;
			std::cout << "2: Large data set of random numbers" << std::endl;
			std::cout << "3: Already sorted data set-numbers sorted low to high" << std::endl;
			std::cout << "4: Reverse sorted data set-numbers sorted high to low" << std::endl;
			std::cout << "5: Data set of one number repeating" << std::endl;
			std::cout << "6: Keep current data set" << std::endl;

			int option2;
			std::cin >> option2;
			if (option2 == 1)
			{
				std::cout << "Enter the max data range." << std::endl;
				int userNum;
				std::cin >> userNum;
				dataSet = unsortedData.randomNumbers(userNum);
				std::cout << "Data Set Generated" << std::endl;
				std::cout<<std::endl;

			}
			else if (option2 == 2)
			{
				std::cout << "Enter the max data range." << std::endl;
				int userNum;
				std::cin >> userNum;
				dataSet = unsortedData.randomNumbersLarge(userNum); 
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option2 == 3)
			{
				dataSet = unsortedData.alreadySorted();
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option2 == 4)
			{
				dataSet = unsortedData.reverseSorted();
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option2 == 5)
			{
				std::cout << "Which number would you like to use?" << std::endl;
				int userNum;
				std::cin >> userNum;
				dataSet = unsortedData.sameNumber(userNum);
				std::cout << "Data Set Generated" << std::endl;
				std::cout << std::endl;
			}
			else if (option == 6)
			{
				std::cout << "No changes made to data set" << std::endl;
				std::cout << std::endl;
			}

		}
		else if(option==2)
		{
			quickSort(dataSet, 0, dataSet.size() - 1);
			for (int i = 0; i < dataSet.size(); i++)
			{
				std::cout << dataSet[i] << std::endl;
			}
		}
		else if (option == 0)
			break;
	}

}

void quickSort(std::vector<int>& unsorted, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(unsorted, low, high);
		quickSort(unsorted, low, pivot - 1);
		quickSort(unsorted, pivot + 1, high);
	}

}

int partition(std::vector<int>& unsorted, int low, int high)
{
	int pivot = unsorted[low];
	int upIndex = low;
	int downIndex = high;
	while (upIndex < downIndex)
	{
		//Increment up until up selects the first element greater than the pivot value, or up=end
		for (int i = upIndex; i<high; i++)
		{
			if (unsorted[upIndex] > pivot)
				break;
			upIndex++;
		}
		//Decrement down until down selects the first element less than or equal to the pivot value or up=first.
		for (int i = downIndex; i>low; i--)
		{
			if (unsorted[downIndex]<=pivot)
				break;
			downIndex--;
		}
		if (upIndex < downIndex)
		{
			int newUp = unsorted[downIndex];
			int newDown = unsorted[upIndex];
			unsorted[upIndex] = newUp;
			unsorted[downIndex] = newDown;
		}
		
	}
	
	//Up is to the left of down, so swap pivot value with down value
	int newPivot = unsorted[downIndex];
	unsorted[low] = newPivot;
	unsorted[downIndex] = pivot;
	pivot = newPivot;

	return downIndex;
}