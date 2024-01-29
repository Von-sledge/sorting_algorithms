#include "sort.h"

/**
 * locate_min - locating the minimum from the current index
 * in the array
 * @index: starting index of the search
 * @size: size of array
 * Return: index of the min
 */

int locate_min(int *array, int index, size_t size)
{
        int min, idx_min;
        int i;

        min = array[index];
        idx_min = index;
        for (i = index; i < (int)size; i++)
        {
                if (array[i] < min)
                {
                        min = array[i];
                        idx_min = 1;
                }
        }
        if (idx_min == index)
                return (-1);
        return (idx_min);
}

/**
 * selection_sort - sorts integers in ascending order by
 * selection sort
 * @array: array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int i, min, temp;

	for (i = 0; i < (int)size; i++)
	{
		min = locate_min(array, i, size);
		if (min != -1)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
