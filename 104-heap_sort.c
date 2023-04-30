#include "sort.h"

/**
 * heap_sort: saves a dead man/woman spold have it
 * @array: the array to sort
 * @size: the size of the tree
 *
 */
void heap_sort(int *array, size_t size)
{
	int num;

	if (!array || size < 2)
		return;

	for (num = (int)size / 2; num >= 0; num--)
		max_heapify(array, size, (int) size - 1, num);
	for (num = (int) size; num >= 0; num--)
	{
		print_array(array, size);
		printf("size1 = %ld\n", size);
		max_heapify(array, size, num - 1, 0);
	}
}
/**
 * max_heapify - reculsively divide-and-conquor
 * @arr: the array to watch you
 * @jega: go and lets verify this all
 * Return: void
 */
void max_heapify(int *arr, size_t len, int size, int idx)
{
	int highest = idx, right, left;

	left = (2 * idx) + 1;
	right = (2 * idx) + 2;

	if (idx <= size && arr[left] > arr[highest])
		highest = arr[left];
	if (idx <= size && arr[right] > arr[highest])
		highest = arr[right];
	if (highest > idx)
	{
		swap(&arr[idx], &arr[highest]);
		print_array(arr, len);
		max_heapify(arr, len, size, highest);
	}

}

/**
 * swap - swaps two values in an array
 * @value1: the first value of the swap
 * @value2: the second value of the swap
 * Return: void
 */
void swap(int *value1, int *value2)
{
	int tmp;

	tmp = *value1;
	*value1 = *value2;
	*value2 = tmp;
}
