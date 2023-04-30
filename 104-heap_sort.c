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

	size--;
	for (num = (int)(size / 2); num >= 0; num--)
	{
		print_array(array, 2);
		max_heapify(array, (int) size, num);
	}
	for (num = (int) size; num >= 0; num--)
		max_heapify(array, num, 1);
}
/**
 * max_heapify - reculsively divide-and-conquor
 * @arr: the array to watch you
 * @jega: go and lets verify this all
 * Return: void
 */
void max_heapify(int *arr, int size, int idx)
{
	int highest = idx, right, left;

	left = (2 * idx) + 1;
	right = (2 * idx) + 2;

	if (idx <= size && arr[left] > arr[highest])
		highest = arr[left];
	if (idx <= size && arr[right] > arr[highest])
		highest = arr[right];
	print_array(arr, size);
	if (highest != idx)
	{
		swap(&arr[idx], &arr[highest]);
		max_heapify(arr, size, highest);
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


#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    heap_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
