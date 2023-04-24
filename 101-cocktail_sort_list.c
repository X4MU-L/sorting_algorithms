#include "sort.h"

/**
 * cocktail_sort_list - sorts a linked list using a cocktail sorting
 * algorithm
 * Description: the function implements a two way bubble sort to sort a linked
 * while also making if possible to identify an already sorted list at O(n)
 * @list: the head of the linked list
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	int flag = 0;
	listint_t *tail, *tmp;

	if (!*list || !(*list)->next)
		return;
	tail = *list;
	while (tail->next)
		tail = tail->next;
	do {
		flag = 0;
		tmp = *list;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_list(list, &tail, tmp, tmp->next);
				flag = 1;
				tmp = tmp->prev;
			}
			tmp = tmp->next;
		}
		if (!flag)
			break;

		flag = 0;
		tmp = tail;
		while (tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_list(list, &tail, tmp->prev, tmp);
				flag = 1;
				tmp = tmp->next;
			}
			tmp = tmp->prev;
		}
	} while (flag);
}

/**
 * swap_list - swaps the offset of a doubly linked list
 * @head: the head of the doubly linked list
 * @tail: the tail of the doubly linked list
 * @left: the prev node before the @right node in a doubly linked list
 * @right: the next node atfer the @left node in a doubly linked list
 * Return: void
 */
void swap_list(listint_t **head, listint_t **tail, listint_t *left,
	       listint_t *right)
{
	left->next = right->next;
	if (right->next)
		right->next->prev = left;
	else
		*tail = left;
	right->next = left;
	right->prev = left->prev;
	if (!left->prev)
		*head = right;
	else
		left->prev->next = right;
	left->prev = right;
	print_list(*head);
}
