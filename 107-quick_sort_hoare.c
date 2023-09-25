#include "sort.h"

/**
 * swap - Swaps two elements in an array
 *
 * @array: The array containing elements to be swapped
 * @i: Index of the first element to be swapped
 * @j: Index of the second element to be swapped
 * @size: Number of elements in @array
 */
void swap(int *array, int i, int j, size_t size)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme
 *
 * @array: The array to be partitioned
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: Number of elements in @array
 * Return: Index of the pivot element after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i > j)
			return j;

        if (i != j)
			swap(array, i, j, size);
	}
}

/**
 * _quick_sort_hoare - Recursive function to perform Quick Sort
 *
 * @array: The array to be sorted
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: Number of elements in @array
 */
void _quick_sort_hoare(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, low, high, size);

		_quick_sort_hoare(array, low, pivot_index, size);
		_quick_sort_hoare(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array using Quick Sort with Hoare Partition scheme
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;
	_quick_sort_hoare(array, low, high, size);
}
