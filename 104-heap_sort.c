#include "sort.h"

/**
 * sift_down - Sifts down an element to maintain the heap property
 *
 * @array: The input array
 * @size: Size of the array
 * @start: The starting index of the subtree
 * @end: The ending index of the subtree
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	int tmp;

	while (root * 2 + 1 <= end)
	{
		size_t child = root * 2 + 1;
		size_t swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		/* Swap elements and print the array */
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		print_array(array, size);

		root = swap;
	}
}

/**
 * heapify - Builds a max heap from an array
 *
 * @array: The input array
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	int i;

	/* Build a max heap from the array */
	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, size, i, size - 1);
	}
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm
 *
 * @array: The input array
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (array == NULL || size <= 1)
		return;

	/* Build a max heap */
	heapify(array, size);

	/* Perform the heap sort */
	for (i = size - 1; i > 0; i--)
	{
		/* Swap the root (maximum element) with the last element */
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);

		/* Heapify the reduced heap */
		sift_down(array, size, 0, i - 1);
	}
}
