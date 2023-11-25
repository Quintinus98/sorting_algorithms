#include "sort.h"

/**
 * quick_sort - sorts an array of integers using quick_sort
 * @array: array of integers
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quickSort(array, 0, size - 1, size);
}

/**
 * quickSort - performs the quicksort
 * @low: low value
 * @high: high value
 * @size: size of the array
 * @array: array of integers
*/
void quickSort(int *array, int low, int high, int size)
{
	int pivot;

	if (low < high)
	{
		pivot = divide_up(array, low, high, size);
		quickSort(array, low, pivot - 1, size);
		quickSort(array, pivot + 1, high, size);
	}
}

/**
 * divide_up - divides up the array into smaller fragments
 * @low: low value
 * @high: high value
 * @size: size of the array
 * @array: array of integers
 * Return: position of sorted value
*/
int divide_up(int *array, int low, int high, int size)
{
	int k, i;

	for (k = i = low; i < high; i++)
		if (array[i] < array[high])
		{
			if (k < i)
			{
				swap(&array[i], &array[k]);
				print_array(array, size);
			}
			k++;
		}

	if (array[k] > array[high])
	{
		swap(&array[k], &array[high]);
		print_array(array, size);
	}

	return (k);
}

/**
 * swap - Swaps the address of two ints in an array
 * @a: address of a - value
 * @b: address of b - value
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
