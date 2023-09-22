#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list of integers
 * by inserting each element at the required position
 * @list: the linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next, *tmp1, *tmp2;

	if (!list || !(*list)->next)
		return; /* The list has 0 or 1 items */
	current = (*list)->next;

	while (current)
	{
		tmp1 = current;
		tmp2 = current->next;
		while (tmp1->prev && tmp1->n < tmp1->prev->n)
		{
			prev = tmp1->prev;
			next = tmp1->next;
			if (prev->prev)
				prev->prev->next = tmp1;
			if (next)
				next->prev = prev;
			tmp1->prev = prev->prev;
			tmp1->next = prev;
			prev->next = next;
			prev->prev = tmp1;
			if (!tmp1->prev)
				*list = tmp1;
			print_list(*list);
		}
		current = tmp2;
	}
}
