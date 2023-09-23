#include "sort.h"

/**
 * traverse_forward - Helper function to
 * perform forward pass of Cocktail Shaker Sort
 * @list: A pointer to the head of the doubly linked list.
 * @swapped: A pointer to the swapped flag.
 */
void traverse_forward(listint_t **list, int *swapped)
{
	listint_t *current = *list;
	listint_t *tmp;

	while (current->next != NULL)
	{
		if (current->n > current->next->n)
		{
			if (current->prev != NULL)
				current->prev->next = current->next;
			else
				*list = current->next;
			current->next->prev = current->prev;
			tmp = current->next->next;
			current->next->next = current;
			current->prev = current->next;
			current->next = tmp;
			if (tmp != NULL)
				tmp->prev = current;
			*swapped = 1;
			print_list(*list);
		}
		else
			current = current->next;
	}
}

/**
 * traverse_backward - Helper function to
 * perform backward pass of Cocktail Shaker Sort
 * @list: A pointer to the head of the doubly linked list.
 * @swapped: A pointer to the swapped flag.
 */
void traverse_backward(listint_t **list, int *swapped)
{
	listint_t *current = *list, *tmp;

	while (current->prev != NULL)
	{
		if (current->n < current->prev->n)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			tmp = current->prev->prev;
			current->prev->prev = current;
			current->next = current->prev;
			current->prev = tmp;
			if (tmp != NULL)
				tmp->next = current;
			if (current->prev == NULL)
				*list = current;
			*swapped = 1;
			print_list(*list);
		}
		else
			current = current->prev;
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using
 * the Cocktail Shaker (Bidirectional Bubble Sort) algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		traverse_forward(list, &swapped);
		if (!swapped)
			break;
		traverse_backward(list, &swapped);
	}
}
