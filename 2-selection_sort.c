#include "sort.h"

/**
 * selection_sort - sorts an array of integer by
 * moving the smallest number to it's position
 * @array: the array being sorted
 * @size: the size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, min, tmp;

	if (!array || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}

	}
}
