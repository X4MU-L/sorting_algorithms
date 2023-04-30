#include "sort.h"

/**
 * heap_sort - sorts an array of integers using a heap tree algorithm
 * Description: the algoritms sifts the highest element in an array to the
 * start index/root starting at the last "non-leaf element" - this method
 * is also know as heapify, when done we loop from the last element swapping
 * the first (sorted/highest element at this time) with the last and sift the
 * array on each iteration decrementing the size of the array from the back
 * @array: the array to sort
 * @size: the size of the tree
 *
 */
void heap_sort(int *array, size_t size)
{
	int num;

	if (!array || size < 2)
		return;

	for (num = (size / 2) - 1; num >= 0; num--)
		max_heapify(array, size, size - 1, num);
	for (num = size - 1; num > 0; num--)
	{
		swap(&array[0], &array[num]);
		print_array(array, size);
		max_heapify(array, size, num - 1, 0);
	}
}
/**
 * max_heapify - reculsively sift the max element in an array to
 * non-leaf position or parent position till root
 * @arr: the array to sift
 * @size: the number of elements in @arr
 * @idx: the index to start sifting
 * @n: the last index to stop sifting
 * Return: void
 */
void max_heapify(int *arr, size_t size, int n, int idx)
{
	int highest = idx, right, left;

	left = 2 * idx + 1;
	right = left + 1;

	if (left <= n && arr[left] > arr[highest])
		highest = left;
	if (right <= n && arr[right] > arr[highest])
		highest = right;
	if (highest != idx)
	{
		swap(&arr[idx], &arr[highest]);
		print_array(arr, size);
		max_heapify(arr, size, n, highest);
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
