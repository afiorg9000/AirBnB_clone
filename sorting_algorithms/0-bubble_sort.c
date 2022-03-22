#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the Bubble sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{

	unsigned int count, tmp_element, element;

	for (count = 0; count < size; count++)
	{
		for (element = 0; element < size - count - 1; element++)
		{
			if (array[element] > array[element + 1])
			{
				tmp_element = array[element];
				array[element] = array[element + 1];
				array[element + 1] = tmp_element;

				print_array(array, size);
			}
		}
	}
}
