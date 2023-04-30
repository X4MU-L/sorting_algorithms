#include "sort.h"

/**
 * get_max - returns the maximum element in @array
 * @array: the array to get max from
 * @size: the size of @array
 * Return: returns the max element of the array
 */

int get_max(int *array, int size)
{
	int max = 0, i;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_count_sort - sorts an array using a base count indexing
 * Description: the algorithm takes the LSD of each number in the array
 * counts its occurances cumulatively for each index 0 - 9
 * increments the running cumulative count of all counts from 0 - 9
 * @array: the array to sort
 * @copy: an array of same size with @array to copy sorted values
 * @size: the size of the array
 * @base: the tens of the numbers in array to sort
 * Return: void
 */

void radix_count_sort(int *array, int *copy, int size, int base)
{
	int i;
	int count_array[10] = {0};

	for (i = 0; i < size; i++)
		count_array[(array[i] / base) % 10]++;
	for (i = 1; i < 10; i++)
		count_array[i] = count_array[i] + count_array[i - 1];
	for (i = size - 1; i >= 0; i--)
		copy[--count_array[(array[i] / base) % 10]] = array[i];
	print_array(copy, size);
}

/**
 * radix_sort - sorts an integer array of numbers greater than
 * or equal to zero using counting sort
 * Description: the algorithm gets the max number in an array
 * sorts an run the counting sort algorithm using its digit place
 * using the LSD (least significant digit) in each tens increamented
 * by the base of the number
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int max;
	size_t base;
	int *copy;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	copy = malloc(sizeof(*array) * size);
	if (copy == NULL)
		return;

	for (base = 1; (max / base) > 0; base *= 10)
	{
		radix_count_sort(array, copy, size, base);
	}
	for (base = 0; base < size; base++)
		array[base] = copy[base];

	free(copy);
}
