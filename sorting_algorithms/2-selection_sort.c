#include "sort.h"

/**
 * selection_sort- sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array of integers
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, swap, min;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	/*One by one move boundary of unsorted subarray*/
	{
		/*Find the minimum element in unsorted array*/
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			/*Swap the found minimum element with the first element*/
			swap = array[min];
			array[min] = array[i];
			array[i] = swap;

			print_array(array, size);
		}
	}

}
