#include "sort.h"

/**
 * counting_sort - sorts an array using a counting sort algorithm
 * Description: counting sort implements a stable sort and does not use
 * comparision
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max, *count, *copy_array;

	if (!array || size < 2)
		return;

	max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	max++;
	count = malloc(sizeof(*count) * max);
	if (count == NULL)
		return;
	copy_array = malloc(sizeof(*array) * size);
	if (copy_array == NULL)
	{
		free(count);
		return;
	}
	count_and_copyarray(array, count, copy_array, max, size);
	free(count);
	free(copy_array);
}
/**
 * count_and_copyarray - implements count array, copy the array
 * and also sort copy_array
 * @array: the input array to sort
 * @count: the count array to update
 * @copy_array: the sorted array
 * @max: the size of the count array
 * @size: the size of the array
 * Return: void
 */
void count_and_copyarray(int *array, int *count, int *copy_array,
			 int max, size_t size)
{
	size_t i;
	int j;

	for (j = 0; j < max; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j < max; j++)
		count[j] = count[j] + count[j - 1];
	print_array(count, max);
	for (j = (int)size - 1; j >= 0; j--)
		copy_array[--count[array[j]]] = array[j];
}
