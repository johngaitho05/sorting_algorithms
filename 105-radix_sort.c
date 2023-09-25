#include "sort.h"

/**
 * get_max - Find the maximum element in an array
 *
 * @array: The array to search
 * @size: Number of elements in the array
 *
 * Return: The maximum element in the array
 */
int get_max(const int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - Sorts an array of integers based on a specific digit
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The exponent for the current digit place value
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int)), count[10] = {0}, k, l;
	size_t i, j;

	if (output == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	/* Count occurrences of each digit in the current place value */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/*
	 * Adjust the count array to store the
	 * actual position of the digits in output
	 */
	for (k = 1; k < 10; k++)
		count[k] += count[k - 1];

	/* Build the output array based on the count and digit positions */
	for (l = size - 1; l >= 0; l--)
	{
		output[count[(array[l] / exp) % 10] - 1] = array[l];
		count[(array[l] / exp) % 10]--;
	}

	/* Copy the sorted elements back to the original array */
	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers using LSD Radix Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int exp, max;

	if (size < 2)
		return;

	max = get_max(array, size);

	/*
	 * Perform counting sort for every digit place value,
	 * from least significant to most significant
	 */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
