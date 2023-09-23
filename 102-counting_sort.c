#include "sort.h"

/**
 * counting_sort - Sorts an array of
 * integers using Counting Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, max, *count;
	int *result;

	if (array == NULL || size <= 1)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (j = 0; j <= max; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);
	result = malloc(size * sizeof(int));
	if (result == NULL)
	{
		free(count);
		return;
	}
	for (j = size - 1; j >= 0; j--)
	{
		result[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = result[i];
	free(count);
	free(result);
}
