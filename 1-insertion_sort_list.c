#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: the linked list to sort
 * Return: Nothing (void function)
 */
void insertion_sort_list(listint_t **list)
{
	int i = 0, j = 0;
	listint_t *temp, *temp2 = *list;

	while (temp2)
	{
		if (temp2->next->n)
		{
			if (temp2->n > temp2->next->n)
			{
				temp = temp2;
				temp2 = temp2->next;
				temp2->next = temp;
			}
		}
		if (temp2->prev->n)
		{
			while (temp2->n < temp2->prev->n)
			{
				temp = temp2;
				temp2 = temp2->prev;
				temp2->prev = temp;
			}
		}
	}
}