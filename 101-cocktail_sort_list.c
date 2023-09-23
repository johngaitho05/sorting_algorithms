#include "sort.h"

/**
 * traverse_forward - Helper function to
 * perform forward pass of Cocktail Shaker Sort
 * @list: A pointer to the head of the doubly linked list.
 * @swapped: A pointer to the swapped flag.
 * @end: the end point past which items are already sorted
 */
void traverse_forward(listint_t **list, int *swapped, listint_t **end)
{
	listint_t *curr = *list;
	listint_t *tmp;

	while (curr->next != *end)
	{
		if (curr->n > curr->next->n)
		{
			if (curr->prev != NULL)
				curr->prev->next = curr->next;
			else
				*list = curr->next;

			curr->next->prev = curr->prev;
			tmp = curr->next->next;
			curr->next->next = curr;
			curr->prev = curr->next;
			curr->next = tmp;

			if (tmp != NULL)
				tmp->prev = curr;

			*swapped = 1;
			print_list(*list);
		}
		else
			curr = curr->next;
	}

	*end = curr; /* Update the end of the sorted part */
}

/**
 * traverse_backward - Helper function to
 * perform backward pass of Cocktail Shaker Sort
 * @list: A pointer to the head of the doubly linked list.
 * @swapped: A pointer to the swapped flag.
 * @start: the starting point before which items are already sorted
 * @end: the end point past which items are already sorted
 */
void traverse_backward(listint_t **list, int *swapped,
					   listint_t **start, listint_t **end)
{
	listint_t *curr = *end;
	listint_t *tmp;

	while (curr->prev != *start)
	{
		if (curr->n < curr->prev->n)
		{
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
			tmp = curr->prev->prev;
			curr->prev->prev = curr;
			curr->next = curr->prev;
			curr->prev = tmp;

			if (tmp != NULL)
				tmp->next = curr;

			if (curr->prev == NULL)
				*list = curr;

			*swapped = 1;
			print_list(*list);
		}
		else
			curr = curr->prev;
	}

	*start = curr; /* Update the start of the unsorted part */
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker
 *                      (Bidirectional Bubble Sort) algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		traverse_forward(list, &swapped, &end);
		if (!swapped)
			break;
		traverse_backward(list, &swapped, &start, &end);
	}
}

