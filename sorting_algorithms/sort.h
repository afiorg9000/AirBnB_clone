#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* sorting prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **head, listint_t **left, listint_t *right);

void selection_sort(int *array, size_t size);

/*quick_sort file prototypes*/
void quick_sort(int *array, size_t size);
void quicksort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void quick_swap(int *i, int *j);


/*advanced tasks*/
void shell_sort(int *array, size_t size);

/*merge_sort file prototypes*/
void merge_sort(int *array, size_t size);
void merge_split(int *array, size_t start, size_t end, int *tmp);
void merge(int *array, size_t start, size_t mid, size_t end, int *tmp);



#endif /* SORT_H */
