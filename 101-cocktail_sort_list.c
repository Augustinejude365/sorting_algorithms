#include "sort.h"

/**
 * swap_node - A finction that Swaps two nodes in a Doubly Link list.
 * @node_a: The first node.
 * @node_b: The second node.
 * @list: The Doubly Link list.
 */
void swap_node(listint_t *node_a, listint_t *node_b, listint_t **list)
{
	listint_t *temp_next_a = node_a->next;
	listint_t *temp_prev_b = node_b->prev;

	if (temp_next_a)
		temp_next_a->prev = node_b;
	if (temp_prev_b)
		temp_prev_b->next = node_a;

	node_a->prev = temp_prev_b;
	node_b->next = temp_next_a;
	node_a->next = node_b;
	node_b->prev = node_a;

	if (*list == node_b)
		*list = node_a;

	print_list(*list);
}

/**
 * cocktail_sort_list - A function that Sorts a Doubly Link list
 * using Cocktail method of sorting.
 * @list: The Doubly Link list to be sorted.
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *kurent, *first = NULL, *last = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;

	do {
		kurent = *list;

		while (kurent->next)
		{
			if (kurent->n > kurent->next->n)
				swap_node(kurent->next, kurent, list);
			else
				kurent = kurent->next;
		}
		last = kurent;

		while (kurent->prev != first)
		{
			if (kurent->n < kurent->prev->n)
				swap_node(kurent, kurent->prev, list);
			else
				kurent = kurent->prev;
		}

		first = kurent;

	} while (first != last);
}
