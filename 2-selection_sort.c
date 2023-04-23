#include "sort.h"

/**
 * selection_sort - sorts an array of integers by selecting
 * the smallest and swapping the required index with the value
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t swap_idx, i, j;
	int smallest, tmp, flag;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		swap_idx = i;
		smallest = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				swap_idx = j;
				flag = 1;
			}
		}
		if (flag)
		{
			tmp = array[swap_idx];
			array[swap_idx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
