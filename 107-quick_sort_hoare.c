#include "sort.h"

/**
 * quick_sort_hoare - sort an array of numbers using hoare quick
 * sorting algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quick_sort(array, 0, (int) size - 1, size);
}

/**
 * hoare_quick_sort - sorts an array of ints reculsively using
 * hoare quick sort algorithm
 * @array: the array to sort
 * @start: the start of the array
 * @end: the end of the array
 * @size: the size of the array
 * Return: void
 */
void hoare_quick_sort(int *array, int start, int end, size_t size)
{
	int idx;

	if (start >= 0 && end >= 0 && start < end)
	{
		idx = partition_hoare(array, start, end, size);
		hoare_quick_sort(array, start, idx, size);
		hoare_quick_sort(array, idx + 1, end, size);
		print_array(array, size);
	}
}

/**
 * partition_hoare - partitions and sorts and array of ints
 * using hoar quick sort algorithm
 * @end: the end of the partition
 * @array: the arrau to sort
 * @size: the size of the array
 * @start: the start of array partition
 * Return: int the index of the pivot
 */
int partition_hoare(int *array, int start, int end, size_t size)
{
	int pivot;
	int i = start - 1;
	int j = end + 1;

	pivot = array[((end - start) / 2) + start];
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {

			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return j;

		swap(&array[i], &array[j]);
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
