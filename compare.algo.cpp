#include <time.h>
#include <iostream>
using namespace std;
 
//  Merge Sort
 
 
void merge(int array[], int const left, int const mid,
	int const right)
{
	clock_t start = clock();
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;


	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0,
		indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
	clock_t end = clock();
}
 
void mergeSort(int array[], int const begin, int const end)
{
	 
	if (begin >= end)
		return;  

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);

}

 
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}
 
//  Quick Sort .
 
int partition(int my_array[], int start, int end)
{
	clock_t start = clock();
 
	int pivot = my_array[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (my_array[i] <= pivot)
			count++;
	}
	
	int pivotIndex = start + count;
	swap(my_array[pivotIndex], my_array[start]);

	 
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (my_array[i] <= pivot) {
			i++;
		}

		while (my_array[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(my_array[i++], my_array[j--]);
		}
	}
	clock_t end = clock();
	return pivotIndex;
}

void quickSort(int my_array[], int start, int end)
{
	clock_t end = clock();
 
	if (start >= end)
		return;
 
	int p = partition(my_array, start, end);

	 
	quickSort(my_array, start, p - 1);

	 
	quickSort(my_array, p + 1, end);
	clock_t end = clock();

}

//  insertion sort
 
void insertionSort(int my_array[], int n)
{
	clock_t start = clock();
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = my_array[i];
		j = i - 1;
 
		while (j >= 0 && my_array[j] > key)
		{
			my_array[j + 1] = my_array[j];
			j = j - 1;
		}
		my_array[j + 1] = key;
	}
	clock_t end = clock();
}
void printArrayinsertion(int my_array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << my_array[i] << " ";
	cout << endl;
}
 
 
//   Bubble sort

void bubbleSort(int my_array[], int n)
{
	clock_t start = clock();
	int i, j;
	for (i = 0; i < n - 1; i++)

 
		for (j = 0; j < n - i - 1; j++)
			if (my_array[j] > my_array[j + 1])
				swap(my_array[j], my_array[j + 1]);
}

 
void printArraybubble(int my_array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << my_array[i] << " ";
	cout << endl;
	clock_t end = clock();
}

 





int main()
{ 
	int my_array[100];
	srand(0);
	int i;
	for (i = 0; i < 100; i++) {
		my_array[i] = rand();

	}
	auto arr_size = sizeof(my_array) / sizeof(my_array[0]);

	cout << "Given array is \n";
	printArray(my_array, arr_size);

	mergeSort(my_array, 0, arr_size - 1);

	cout << "\nmergeSort \n";
	printArray(my_array, arr_size);



	int n = 100 ;
	quickSort(my_array, 0, n - 1);
	cout<<endl << "Quick Sort"<<endl;
	for (int i = 0; i < n; i++) {
		cout << my_array[i] << " ";
	}



	int N = sizeof(my_array) / sizeof(my_array[0]);
	insertionSort(my_array, N);
	cout << endl << "insertion Sort" << endl;
	printArrayinsertion(my_array, N);



	bubbleSort(my_array, N);
	cout<<endl << "bubble Sort: \n";
	printArraybubble(my_array, N);

	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	printf(" The execution time .\n", elapsed);
	return 0;
}
 