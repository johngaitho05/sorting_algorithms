#include <math.h>
#include <stdio.h>
#include "sort.h"

/**
 * print_sub_array - prints a sub array given the start and end index
 * @array: the array from which to extract sub-array
 * @start: starting index of the sub-array
 * @end: closing index of the sub-array
 */
void print_sub_array(int *array, size_t start, size_t end)
{
	size_t i;

	i = start;
	while (array && i <= end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * merge - merges the left and right sub-arrays
 * @array: the array being sorted
 * @tmp: the output array
 * @left_start: start index for the first sub-array
 * @left_end: last index for the first sub-array
 * @right_start: start index for the second sub-array
 * @right_end: last index for the second sub-array
 */
void merge(int *array, int *tmp, size_t left_start,
		   size_t left_end, size_t right_start, size_t right_end)
{
	size_t i = left_start, j = right_start, k = left_start, index;

	printf("Merging...\n");
	printf("[left]: ");
	print_sub_array(array, left_start, left_end);
	printf("[right]: ");
	print_sub_array(array, right_start, right_end);
	/* Merge the two arrays back into the original array */
	while (i <= left_end && j <= right_end)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}
	while (i <= left_end)
		tmp[k++] = array[i++];
	while (j <= right_end)
		tmp[k++] = array[j++];
	/* Copy the merged elements back to the original array */
	for (index = left_start; index <= right_end; index++)
		array[index] = tmp[index];
	printf("[Done]: ");
	print_sub_array(array, left_start, right_end);
}

/**
 * _merge_sort - helper function for subdividing the array
 * @array: the array being sorted
 * @tmp: the output array
 * @left: starting index for the first sub-array
 * @right: starting index for the right sub-array
 */
void _merge_sort(int *array, int *tmp, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		/* If the array has odd length, ensure the right sub-array is larger */
		if ((right - left) % 2 == 0)
			mid -= 1;

		_merge_sort(array, tmp, left, mid);
		_merge_sort(array, tmp, mid + 1, right);

		merge(array, tmp, left, mid, mid + 1, right);
	}
}

/**
 * merge_sort - sorts an array of integers using
 * divide and conquer technique
 * @array: the array being sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = (int *)malloc(size * sizeof(int));

	if (tmp == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	_merge_sort(array, tmp, 0, size - 1);

	free(tmp);
}
