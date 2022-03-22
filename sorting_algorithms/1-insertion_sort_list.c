#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked to be sorted.
 * n is data
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nxtNptr, *prevNptr, *traverse;
	/* ^ nxtNptr is a temporary pointer to what list is pointing to*/


	if (list == NULL || (*list)->next == NULL)
		/*if the list is empty, it will stop*/
		return;

	for (nxtNptr = (*list); nxtNptr != NULL; nxtNptr = traverse)
		/* ^ nxtNptr is the next node pointer to be checked*/
	{
		traverse = nxtNptr->next;
		/* ^ points to the next node in order to move through the list*/
		prevNptr = nxtNptr->prev;
	/* ^ previous node pointer to be checked*/
		while (prevNptr != NULL && nxtNptr->n < prevNptr->n)
		/**
		 * ^ checks if there's a node &&
		 * checks wether the nxt ptr node (ex: 48),
		 * is less than the prev ptr node(ex: 19)
		 */
		{
			swap_nodes(list, &prevNptr, nxtNptr);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @left: A pointer to the first node to swap.
 * @right: the next node pointer to swap.
 */
void swap_nodes(listint_t **head, listint_t **left, listint_t *right)
{
	(*left)->next = right->next;/*assigns the prev node ptr to the nxt node ptr*/
	if (right->next != NULL)/*checks whether the next pointer is a node*/
		right->next->prev = *left;
	/**
	 * ^ The next pointer (ex: 71) takes to the nxt pointer(ex: 13)
	 * and the previous node (x: 13) and
	 * swaps it with the previous pointer(ex: 99)
	 */
	right->prev = (*left)->prev;
	/**
	 * ^ swaps the previous node of the nxt node ptr (ex: 71) and
	 * the prev node of the nxt node ptr (ex: 99) to the sorted node
	 */
	right->next = *left;
	/* ^ swaps the ptrs of the nxt node to the pointers of the prev node*/
	if ((*left)->prev != NULL)
	/* ^ checks whether the prev ptr has a node*/
	{
		(*left)->prev->next = right;
		/**
		 * ^ swaps the nxt ptr to the prev node ptr
		 * of the prev node ptr (ex: swaps 71 to 99)
		 */
	}
	else
	/* ^ used when the program is finishing checking the list*/
		*head = right;
		/* ^ swaps the head to the nxt node ptr (ex: 7)*/
	(*left)->prev = right;
	/* ^ swaps the prev node ptr of 7 to 13 */
	*left = right->prev;
	/*swaps the prev node ptr of 7 to 13 */
}
