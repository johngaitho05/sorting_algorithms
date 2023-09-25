#include "sort.h"

/**
 * compare_swap - Compare and swap two elements if needed
 *
 * @array: The array to be sorted
 * @i: Index of the first element
 * @j: Index of the second element
 * @direction: Sorting direction (1 for ascending, 0 for descending)
 */
void compare_swap(int *array, size_t i, size_t j, int direction)
{
	if ((array[i] > array[j]) == direction)
	{
		/* Swap the elements to maintain the desired order */
		int tmp = array[i];

		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * bitonic_merge - Merge two subarrays in Bitonic order
 *
 * @array: The array to be sorted
 * @low: Starting index of the first subarray
 * @count: Number of elements to be merged
 * @direction: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int direction)
{
	size_t i;

	if (count > 1)
	{
		size_t k = count / 2;

		for (i = low; i < low + k; i++)
			compare_swap(array, i, i + k, direction);

		/* Recursively merge the two halves */
		bitonic_merge(array, low, k, direction);
		bitonic_merge(array, low + k, k, direction);
	}
}

/**
 * _bitonic_sort - Recursive function to perform Bitonic Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @direction: Sorting direction (1 for ascending, 0 for descending)
 * @size: size of the @array
 */
void _bitonic_sort(int *array, size_t low,
							size_t count, int direction, size_t size)
{
	size_t k = count / 2;

	if (count > 1)
	{

		printf("Merging [%lu/%lu] (%s):\n", count, size, direction ? "UP" : "DOWN");
		print_array(array + low, count);

		/* Sort the first half in ascending order */
		_bitonic_sort(array, low, k, 1, size);

		/* Sort the second half in descending order */
		_bitonic_sort(array, low + k, k, 0, size);

		/* Merge the two halves */
		bitonic_merge(array, low, count, direction);

		printf("Result [%lu/%lu] (%s):\n", count, size, direction ? "UP" : "DOWN");
		print_array(array + low, count);

	}
}

/**
 * bitonic_sort - Sorts an array using Bitonic Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
	int direction = 1; /* 1 for ascending, 0 for descending */

	if (size < 2)
		return;
	_bitonic_sort(array, 0, size, direction, size);
}

