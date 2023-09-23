#include "sort.h"
#include <stdio.h>

/**
 * calculate_gap - calculates the gap using knuth sequence
 * @size: size of the array
 * Return: the starting gap
 */
size_t calculate_gap(size_t size)
{
	size_t gap = 1;

	while (gap <= size / 3)
	{
		gap = gap * 3 + 1;
	}
	return (gap);
}

/**
 * shell_sort - an efficient insertion sort that starts
 * by swapping elements that are wide apart
 * @array: the array being sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = calculate_gap(size), i, j;
	int tmp;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;

			/* Compare and move elements that are 'gap' positions apart */
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = tmp;
		}

		/* Calculate the next gap using Knuth sequence */
		gap = (gap - 1) / 3;

		/* Call print_array every time the interval is decreased */
		print_array(array, size);
	}
}
