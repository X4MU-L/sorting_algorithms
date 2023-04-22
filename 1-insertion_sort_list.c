#include "sort.h"

/**
 * insertion_sort_list - sort a list by sorting each insertion till
 * it reaches it's posible dirable position down the list
 * @list: pointer to a doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *behind, *forward, *cache;

	if (!*list || !(*list)->next)
		return;

	forward = (*list)->next;
	for (; forward; forward = forward->next)
	{
		behind = forward->prev;
		/*store the point of foward so we can get back here*/
		cache = forward;
		for (; behind && forward->n < behind->n; behind = forward->prev)
		{
			/*move behind forward and point to foward next*/
			behind->next = forward->next;
			/*if foward next is not end of list*/
			if (forward->next)
				forward->next->prev = behind;
			forward->prev = behind->prev;
			forward->next = behind;

			/*if behind at start of list, update head*/
			if (behind->prev == NULL)
				(*list) = forward;
			else
				behind->prev->next = forward;
			behind->prev = forward;
			print_list((const listint_t *)(*list));
		}
		/*move forward to previous point*/
		forward = cache;
	}
}
