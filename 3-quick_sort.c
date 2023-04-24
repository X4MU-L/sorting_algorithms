#include "sort.h"

/**
 * quick_sort - sorts an array of integers using lomuto
 * quick sort algorthm
 * @array: the array to sort
 * @size: the size of the array
 *nReturn: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_quicksort(array, 0, (int) size - 1, size);
}

/**
 * lomuto_quicksort - reculsively sorts an array of integers using
 * lomtumo techniques while partitioning the array on each call
 * @array: the array to sort
 * @start: the start of the partitioned array
 * @end: the end of the partitioned array
 * @size: the initial size of the array
 * Return: void
 */
void lomuto_quicksort(int *array, int start, int end, size_t size)
{
	int idx;

	if (start >= end || start < 0)
		return;

	idx = partition(array, start, end, size);
	lomuto_quicksort(array, start, idx - 1, size);
	lomuto_quicksort(array, idx + 1, end, size);
}


/**
 * partition - partions and sorts an array using the last index as pivot
 * @array: the array to sort
 * @start: the start of the partitioned array
 * @end: the end of the partitioned array
 * @size: the initial size of the array
 * Return: end of the next partion to sort
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot, pivot_idx, i, tmp;

	pivot = array[end];
	pivot_idx = end;

	for (i = end - 1; i >= start; i--)
	{
		if (array[i] > pivot)
		{
			pivot_idx--;
			tmp = array[pivot_idx];
			array[pivot_idx] = array[i];
			array[i] = tmp;
		}
	}
	tmp = array[pivot_idx];
	array[pivot_idx] = array[end];
	array[end] = tmp;
	print_array(array, size);
	return (pivot_idx);
}
