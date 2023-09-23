#include "sort.h"
#include <stdio.h>

/**
 * partition - helper function for sorting the array
 * by recursively moving the last element to its correct position
 * @array: the array to sort
 * @low: sub array start index
 * @high: subarray end index
 * @size: size of the original array
 */
void partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, j, tmp;

	if (low >= high)
		return;

	for (j = low; j < high; j++)
	{
		if (array[j] < array[high])
		{
			i += 1;
			if (i < j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	i += 1;
	if (i < j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
	partition(array, low, i - 1, size);
	partition(array, i + 1, high, size);
}

/**
 * quick_sort - sorts an array of integers recursively
 * by placing an element at the correct position
 * @array: the array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size == 1)
		return;

	partition(array, 0, size - 1, size);
}
