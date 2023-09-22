#include "sort.h"

/**
 * bubble_sort - sorts an array of integers by comparing
 * adjacent elements and swapping them if they are not sorted
 * @array: The array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, swaps, tmp;

	for (i = size - 1; i > 0; i--)
	{
		swaps = 0;
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swaps++;
				print_array(array, size);
			}
		}
		if (!swaps)
			break;
	}
}
