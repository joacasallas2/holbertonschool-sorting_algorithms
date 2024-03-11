#include "sort.h"
#include <unistd.h>
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: the linked list to sort
 * Return: Nothing (void function)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *restPrev = NULL, *prev, *current, *next, *restNext = NULL, *node = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	prev = *list;
	current = *list;
	restPrev = prev->prev;
	while (current->next)
	{
		next = current->next;
		next->prev = current;
		next->next = current->next->next;
		restNext = next->next;
		if (current->n > next->n)
		{
			current->next = NULL;
			current->prev = NULL;
			next->next = NULL;
			next->prev = NULL;
			node = current;
			current = next;
			next = node;
			prev->next = current;
			current->prev = prev;
			current->next = next;
			next->prev = current;
			next->next = restNext;
			print_list(*list);
			while (current->prev)
			{
				prev = current->prev;
				if (current->n > prev->n)
				{
					break;
				}
				if (current->n < prev->n)
				{
					restPrev = prev->prev;
					current->next = NULL;
					current->prev = NULL;
					prev->next = NULL;
					prev->prev = NULL;
					node = current;
					current = prev;
					prev = node;
					if (restPrev)
					{
						restPrev->next = prev;
						prev->prev = restPrev;
						prev->next = current;
						current->prev = prev;
						current->next = next;
					}
					else
					{
						prev->prev = NULL;
						prev->next = current;
						current->prev = prev;
						current->next = next;
						*list = prev;
					}
					print_list(*list);
				}
				next = current;
				current = current->prev;
			}
		}
		restPrev = prev;
		prev = current;
		current = current->next;
	}
}
