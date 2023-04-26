#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

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

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int start, int end, size_t size);
void lomuto_quicksort(int *array, int start, int end, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_list(listint_t **head, listint_t **tail, listint_t *left,
	       listint_t *right);
void copy_sorted_array(int *array, int *copy, size_t size);
void count_and_copyarray(int *array, int *count, int *copy_array,
			 int max, size_t size);
void counting_sort(int *array, size_t size);
void copy_sorted_array(int *array, int *sorted, size_t size);
void merge_sort(int *array, size_t size);
void merge_array(int *A, int start, int mid, int end, int *B);
void top_down_merge(int *copy_array, int start, int end, int *array);
int *create_copy_array(int *array, size_t size);
void swap(int *value1, int *value2);
int partition_hoare(int *array, int start, int end, size_t size);
void hoare_quick_sort(int *array, int start, int end, size_t size);

#endif /*SORT_H*/
