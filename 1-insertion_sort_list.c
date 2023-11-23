#include "sort.h"

/**
 * swap_start - Swap for start position
 * @ptr: pointer to swap with the next pointer (temp)
 * @start: start pointer to be updated.
*/
void swap_start(listint_t **ptr, listint_t **start)
{
	listint_t *temp = (*ptr)->next;

	/** Swap for Start position */
	(*ptr)->prev = (*ptr)->next;
	(*ptr)->next = temp->next;
	temp->next->prev = temp->prev;
	temp->next = temp->prev;
	temp->prev = NULL;
	(*start) = (*ptr)->prev;
}

/**
 * swap_middle - Swap for middle position
 * @ptr: pointer to swap with the next pointer (temp)
*/
void swap_middle(listint_t **ptr)
{
	listint_t *temp = (*ptr)->next, *temp2 = (*ptr)->next->next;

	(*ptr)->prev->next = temp;
	temp->prev = temp->prev->prev;
	temp->next = (*ptr);
	(*ptr)->prev = temp;
	(*ptr)->next = temp2;
	temp2->prev = (*ptr);
}


/**
 * swap_last - Swap for last position
 * @ptr: pointer to swap with the next pointer (temp)
*/
void swap_last(listint_t **ptr)
{
	listint_t *temp = (*ptr)->next;

	(*ptr)->prev->next = (*ptr)->next;
	temp->next = (*ptr);
	temp->prev = (*ptr)->prev;
	(*ptr)->prev = temp;
	(*ptr)->next = NULL;
}

/**
 * _swap - Swaps the elements
 * @ptr: pointer to swap with the next pointer (temp)
 * @start: start pointer to be updated
 * Return: 1 if swapped 0 if not swapped
*/
int _swap(listint_t **ptr, listint_t **start)
{
	int flag = 0;

	if (((*ptr)->n > (*ptr)->next->n) && (*ptr)->prev == NULL)
	{
		swap_start(ptr, start);
		flag = 1;
	}
	else if (((*ptr)->n > (*ptr)->next->n) && (*ptr)->next->next == NULL)
	{
		swap_last(ptr);
		flag = 1;
	}
	else if (((*ptr)->n > (*ptr)->next->n))
	{
		swap_middle(ptr);
		flag = 1;
	}

	return (flag);
}

/**
 * insertion_sort_list -  sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: array of list items
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *start = *list, *ptr, *check;
	int flag = 0;

	if (!list)
		return;
	ptr = start;
	while (ptr->next != NULL)
	{
		flag = _swap(&ptr, &start);
		if (flag == 1)
		{
			print_list(start);
			check = ptr->prev->prev;
			while (check != NULL && flag != 0)
			{
				flag = _swap(&check, &start);
				if (flag == 0)
					check = check->next;
				else
					print_list(start);
				check = check->prev->prev;
			}
		}
		else
			ptr = ptr->next;
	}
	*list = start;
}
