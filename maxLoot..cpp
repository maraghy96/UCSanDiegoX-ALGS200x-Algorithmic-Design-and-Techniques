#include <iostream>
#include <math.h>

using namespace std;

typedef struct 
{
	float weight;
	float totalValue;
	float value ;
}item_t;


/*
Name of the function: void quickSortStruct
source: 
gubatron/quicksort.cpp (https://gist.github.com/gubatron/7c659e65d19681476274abe7c39875cc)

*/ 
void quickSortStruct(item_t arr[], int length, bool reverse) {
	if (length <= 1) {
		return;
	}
	const float pivot_count = arr[length / 2].value;
	float smaller_length = 0;
	float bigger_length = 0;
	float equal_length = 0;

	for (int i = 0; i < length; i++) {
		if (!reverse) {
			if (arr[i].value < pivot_count) smaller_length++;
			if (arr[i].value > pivot_count) bigger_length++;
		}
		else {
			if (arr[i].value > pivot_count) smaller_length++;
			if (arr[i].value < pivot_count) bigger_length++;
		}
		if (arr[i].value == pivot_count) equal_length++;
	}

	auto smaller = new item_t[smaller_length];
	auto bigger = new item_t[bigger_length];
	auto equal = new item_t[equal_length];

	int smaller_i = 0;
	int bigger_i = 0;
	int equal_i = 0;

	// comparisons, this part should be pluggable to make this generic
	for (int i = 0; i < length; i++) {
		if (!reverse) {
			if (arr[i].value < pivot_count) smaller[smaller_i++] = arr[i];
			if (arr[i].value > pivot_count) bigger[bigger_i++] = arr[i];
		}
		else {
			if (arr[i].value > pivot_count) smaller[smaller_i++] = arr[i];
			if (arr[i].value < pivot_count) bigger[bigger_i++] = arr[i];
		}
		if (arr[i].value == pivot_count) equal[equal_i++] = arr[i];
	}

	quickSortStruct(smaller, smaller_length, reverse);
	quickSortStruct(bigger, bigger_length, reverse);

	int j = 0;
	// now overwrite the original array with:
	// smaller + equal + bigger

	for (int i = 0; i < smaller_length; i++) arr[j++] = smaller[i];
	for (int i = 0; i < equal_length; i++) arr[j++] = equal[i];
	for (int i = 0; i < bigger_length; i++) arr[j++] = bigger[i];
}

float maxLoot(item_t *stolenItem, int n, int knapSackWeight) 
{
	float sum = 0;
	quickSortStruct(stolenItem, n, true);

	
		for (int i = 0; i < n; i++) 
		{
			if(stolenItem[i].weight < knapSackWeight)
			{
				sum = sum + (stolenItem[i].weight * stolenItem[i].value);
				knapSackWeight = knapSackWeight - stolenItem[i].weight;
			}
			else
			{
				sum = sum + (knapSackWeight* stolenItem[i].value);
				knapSackWeight = knapSackWeight - knapSackWeight;
			}
		}
	return sum;
}

int main() 
{

	int numOfItems;
	cin >> numOfItems;
	int knapSackWeight;
	cin >> knapSackWeight;
	float sum = 0;

	item_t *totalItems = new item_t[numOfItems];
	for(int i = 0; i < numOfItems; i++)
	{
		cin >> totalItems[i].totalValue;
		cin >> totalItems[i].weight;
		totalItems[i].value = totalItems[i].totalValue / totalItems[i].weight;
	}

	sum = maxLoot(totalItems, numOfItems, knapSackWeight);
	cout << sum << endl;
}
