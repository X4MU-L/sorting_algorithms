#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending other
 * Description: shell_sort uses a defined sequence to implement insertion sort
 * this particular algorithm uses Knuth sequence <n+1 = n * 3 + 1>
 * e.g 1, 4, 13, 40, 121, ... reverse method <n = n-1/3>
 * @array: the array of ints to sort
 * @size: the length of the array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t n = 1, i, j;
	int tmp;

	if (!array || size < 2)
		return;
	while (n < size)
		n = n * 3 + 1;

	for (; n > 0; n /= 3)
	{
		for (i = n; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= n && array[j - n] > tmp; j -= n)
				array[j] = array[j - n];

			array[j] = tmp;
		}
		if (n < size)
			print_array(array, size);
	}
}
