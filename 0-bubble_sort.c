#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using Bubble_sort
 * @array: array of integers
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t sorted = 0, i = 0, temp;

	while (sorted != 1)
	{
		sorted = 1;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				sorted = 0;
				print_array(array, size);
			}
		}
	}
}
