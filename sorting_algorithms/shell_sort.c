/* Shell Sort in C programming */

#include <stdio.h>

/* Shell sort */
void shellSort(int array[], int size)
{
	/* Rearrange elements at each n/2, n/4, n/8, ... intervals*/
  for (int gap = size / 2; gap > 0; gap /= 2)
  /* ^ Assess the array in gaps starting at half the array size*/
  {
    for (int i = gap; i < size; i += 1)
	/* Index at the right value of each gap */
	{
      int temp = array[i];/* Take a copy of the value */
      int j;
      for (j = i; j >= gap && array[j - gap] > temp; j -= gap) 
	  {
	/* Compare the values in the sub lists and swap where necessary */
        array[j] = array[j - gap];
      }
      array[j] = temp;
    }
  }
}

// Print an array
void printArray(int array[], int size) 
{
  for (int i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  int data[] = {9, 8, 3, 7, 5, 6, 4, 1};
  int size = sizeof(data) / sizeof(data[0]);
  shellSort(data, size);
  printf("Sorted array: \n");
  printArray(data, size);
}

