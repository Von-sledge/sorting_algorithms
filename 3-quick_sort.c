#include "sort.h"

/**
 * swap - positions of two elements into an array
 * @array: array
 * @item1: array element
 * @item2: array element
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * lomuto_partition - sorting implemenation
 * @array: array to be used
 * @first: first array element
 * @last: last array element
 * @size: size array
 * Return: position of the last element sorted
 */

int lomuto_partition(int *array, ssize_t first, ssize_t last, ssize_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}

	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * qs - quicksort algorithm implementation
 * @array: array to be used
 * @first: first array element
 * @last: last element of array
 * @size: size of array
 */
void qs(int *array, ssize_t first, ssize_t last, ssize_t size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort - quicksort algorithm implementation
 * @array: array
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
