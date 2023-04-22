#include "sort.h"

/**
 * bubble_sort - sorts an array of int by bubbling up the
 * highest value up the array
 * @array: the array to sort
 * @size: the size of the array
 * Description: Bubble sort algorithm has a best case scenerio
 * of O(n) and a worst case scenerio of O(n^2)
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, swap = 1, n = size;

	if (size <= 1)
		return;

	while (swap)
	{
		swap = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				array[i] ^= array[i + 1];
				array[i + 1] ^= array[i];
				array[i] ^= array[i + 1];
				swap = 1;
				print_array(array, size);
			}
		}
		n--;
	}
}
