#include "sort.h"

/**
 * selection_sort - sorts an array of integers using selection_sort
 * @array: array of integers
 * @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, k = 0;
	size_t pos = 0, sorted = 0;
	int temp;

	while (pos < size)
	{
		sorted = 0;
		temp = array[pos];
		for (i = pos + 1; i < size; i++)
		{
			if (temp > array[i])
			{
				k = i;
				sorted = 1;
				temp = array[i];
			}
		}
		if (sorted)
		{
			temp = array[k];
			array[k] = array[pos];
			array[pos] = temp;
			print_array(array, size);
		}
		pos++;
	}
}
