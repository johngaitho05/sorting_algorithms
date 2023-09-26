#include "stdlib.h"
#include "string.h"
#include "deck.h"

/**
 * node_value - computes the value of
 * a node based on it's card
 * @node: a node from a deck of cards
 * Return: integer representation of the node
 */
int node_value(deck_node_t *node)
{
	const card_t *card = node->card;
	int value = card->kind * 100;

	if (strcmp(card->value, "Ace") == 0)
		value += 1;
	else if (strcmp(card->value, "Jack") == 0)
		value += 11;
	else if (strcmp(card->value, "Queen") == 0)
		value += 12;
	else if (strcmp(card->value, "King") == 0)
		value += 13;
	else
		value += atoi(card->value);

	return (value);

}

/**
 * sort_deck - sorts a deck of card
 * using insertion sort algorithm
 * @deck: a doubly linked list made of deck nodes
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *prev, *next, *tmp1, *tmp2;

	if (!deck || !(*deck)->next)
		return; /* The deck has 0 or 1 items */
	current = (*deck)->next;

	while (current)
	{
		tmp1 = current;
		tmp2 = current->next;
		while (tmp1->prev && node_value(tmp1) < node_value(tmp1->prev))
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
				*deck = tmp1;
		}
		current = tmp2;
	}
}
