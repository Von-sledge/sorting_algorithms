#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in an ascending
 * order
 * @list - List to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;

	while (node != NULL)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 * swap_node - swaps a node with its previous node
 * @node: Curent node.
 * @list: linked lists
 * Return: pointer to the current position
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev, *current;

	prev = node->prev;
	current = node;

	prev->next = current->next;
	if (current->next)
		current->next->prev = prev;
	current->next = prev;
	current->prev = prev->prev;
	prev->prev = current;
	
	if (current->prev)
		current->prev->next = current;
	else
		*list =  current;
	return (current);
}
