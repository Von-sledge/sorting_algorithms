#include "sort.h"

/**
 * swap - swap two int
 * @a: integer parameter
 * @b: integer parameter
 * Return: (void) swap int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partition an array and using pivot
 * @array: array to be used
 * @low: integer parameter
 * @high: integer parameter
 * @size: size of the array (size_t)
 * Return: index of pivot (int)
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j = high;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}

/**
 * hoare_qsort - sorting recursively an array
 * @array: array to be sorted
 * @low: lowest value of the array
 * @high: highest value of the array
 * @size: size of the array
 * Return: void
 */

void hoare_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		if (i > low)
			hoare_qsort(array, low, i, size);
		hoare_qsort(array, i + 1, high, size);
	}
}

/**
 * quick_sort_hoare - quick sort algorithms using Hoare partition
 * @array: array to sort
 * @size: size of the array
 * Return: sorted array (void)
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_qsort(array, 0, size - 1, size);
}
