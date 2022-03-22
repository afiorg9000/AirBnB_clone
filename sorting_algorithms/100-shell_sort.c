#include "sort.h"

/**
 * shell_sort- Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of array
 * intervals are gaps
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, idx, i;
	int tmp;

	if (size < 2 || array == NULL)
	{
		return;
	}

	while (n < size)
	{
	/* finds the max gap*/
		n = n * 3 + 1;
	}

	n /= 3;
	/*decreases gap sequence*/

	while (n > 0)
	{
		for (idx = n; idx < size; idx++)
		/*compares values from begining and from gap*/
		{
			tmp = array[idx];
			for (i = idx; i >= n && array[i - n] > array[idx]; i -= n)
				array[i] = array[i - n];
			array[i] = tmp;
		}
		n /= 3;
		print_array(array, size);
	}
}

