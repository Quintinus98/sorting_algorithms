#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_start(listint_t **ptr, listint_t **start);
void swap_middle(listint_t **ptr);
void swap_last(listint_t **ptr);

#endif
