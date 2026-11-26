#include <random>
#include "QuickSort.h"

void quickSort(std::vector<int>& unsorted, int low, int high, QuickSortStats& stats)
{
	if (low < high)
	{
		int pivot = partition(unsorted, low, high, stats);
		quickSort(unsorted, low, pivot - 1,  stats);
		quickSort(unsorted, pivot + 1, high, stats);
	}

}

int partition(std::vector<int>& unsorted, int low, int high, QuickSortStats& stats)
{
//Use random number for pivot to prevent stack overflow on already sorted data sets
	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<> range(low, high);
	int randomIndex = range(gen);
	int randomValue = unsorted[randomIndex];
	unsorted[randomIndex] = unsorted[low];
	unsorted[low] = randomValue;

	int pivot = unsorted[low];
	int upIndex = low;
	int downIndex = high;
	while (upIndex < downIndex)
	{
		//Increment up until up selects the first element greater than the pivot value, or up=end
		for (int i = upIndex; i < high; i++)
		{
			stats.comparisons++;
			if (unsorted[upIndex] > pivot)
				break;
			upIndex++;
		}
		//Decrement down until down selects the first element less than or equal to the pivot value or up=first.
		for (int i = downIndex; i > low; i--)
		{
			stats.comparisons++;
			if (unsorted[downIndex] <= pivot)
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

QuickSortStats quickSortStats(std::vector<int>& dataSet) {
	QuickSortStats stats;
	if (dataSet.size() < 2) return stats;
	stats.auxiliaryBytes = stats.auxiliaryBytes + (3 * sizeof(int)); //Three integers are stored; up index, down index, and pivot value. This is a constant for quicksort.
	

	quickSort(dataSet, 0, dataSet.size() - 1, stats);
	return stats;
}
