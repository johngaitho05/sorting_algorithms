#include "sort.h"
#include <stdio.h>

/**
 * calculate_gaps - calculates the comparison
 * gaps using knuth sequence
 * @size: size of the array
 * @gaps_count: a pointer to keep keep track of gaps count
 * Return: the starting gap
 */
size_t *calculate_gaps(size_t size, size_t *gaps_count)
{
	size_t *gaps = NULL, gap = 1, i, tmp;
	*gaps_count = 0;

	while (gap < size)
	{
		(*gaps_count)++;
		gaps = (size_t *)realloc(gaps, sizeof(size_t) * (*gaps_count));
		gaps[*gaps_count - 1] = gap;
		gap = gap * 3 + 1;
	}

	/* Reverse the gap sequence */
	for (i = 0; i < *gaps_count / 2; i++)
	{
		tmp = gaps[i];
		gaps[i] = gaps[*gaps_count - i - 1];
		gaps[*gaps_count - i - 1] = tmp;
	}

	return (gaps);
}

/**
 * shell_sort - an efficient insertion sort that starts
 * by swapping elements that are wide apart
 * @array: the array being sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t *gaps, gap, gaps_count, i, j, k;
	int tmp;

	gaps = calculate_gaps(size, &gaps_count);

	for (k = 0; k < gaps_count; k++)
	{
		gap = gaps[k];

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
		/* Call print_array every time the interval is decreased */
		print_array(array, size);
	}
}
