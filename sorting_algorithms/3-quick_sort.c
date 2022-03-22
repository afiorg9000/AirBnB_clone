#include "sort.h"

/**
 * quick_sort- sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
	{
		return;
	}
	quicksort_recursion(array, 0, size - 1, size);
}

/**
 * quicksort_recursion - applies the recursive divide
 * and conquer portion of the quicksort algorithm
 * to the array
 * @array: array to quicksort
 * @low: lowest elements of array
 * @high: second index of our partition.
 * @size: size of the array
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		/*partition the array by a pivot, and return the pivot element's index*/
		pivot_index = partition(array, low, high, size);

		/**apply quicksort to the left side subarray*/
		quicksort_recursion(array, low, pivot_index - 1, size);

		/* apply quicksort to the right side subarray*/
		quicksort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * partition- artitions the array between low - high indexes by a
 * pivot value and returns the index of the pivot
 * @array: array to quicksort
 * @low: lowest elements of array
 * @high: second index of our partition.
 * @size: size of the array
 * Return: index
 */

int partition(int *array, int low, int high, size_t size)
{

	int i, j, pivot_value;

	pivot_value = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			if (array[i] != array[j])
			{
				quick_swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		quick_swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_swap - swaps the value of what x is pointing to
 *with the value of what y is
 *@x: element
 *@y: element
 */

void quick_swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
