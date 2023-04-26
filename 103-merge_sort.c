#include "sort.h"

/**
 * merge_sort - sorts an array by using "divde and conquer algorithm
 * Description: copy of the array to be sorted is created and passed
 * into a function that reculsively uses the stack to sort and merge
 * the array
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *new_array;

	if (!array || size < 2)
		return;

	new_array = create_copy_array(array, size);
	if (new_array == NULL)
		return;
	top_down_merge(new_array, 0, (int) size, array);
	free(new_array);
}

/**
 * create_copy_array - creates a dynamic array of size @size and copy the
 * values of @array into the new pointer created
 * @array: the array to copy it's values of size @size
 * @size: the size of the original array @array
 * Return: pointer to new array created
 */
int *create_copy_array(int *array, size_t size)
{
	int *new;
	size_t i;

	new = malloc(sizeof(*new) * size);
	if (new == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		new[i] = array[i];
	return (new);
}

/**
 * top_down_merge - reculsively merges an array using "DIVIDE AND CONQUER"
 * approach
 * Description: the top_down_merge reculsively sorts and merge an array by
 * dividing the array into halves on each call and sorting and merging each
 * side, the algorithm alternates the array on each call to avoid a copy back
 * the both arrays @copy_array and @array have the same values, while @array
 * is the array to be sorted
 * @copy_array: a copy of the array to be sorted
 * @start: the start of the array
 * @end: the size of the array
 * @array: the array to be sorted
 * Return: void
 */
void top_down_merge(int *copy_array, int start, int end, int *array)
{
	int mid;

	if (end - start <= 1)
		return;
	mid = (start + end) / 2;
	top_down_merge(array, start, mid, copy_array);
	top_down_merge(array, mid, end, copy_array);
	merge_array(copy_array, start, mid, end, array);
}

/**
 * merge_array - merges or copy the value of @A array for a given
 * sequence between @start and @end in respect to which is greater or
 * lesser
 * @A: the array whose values to copy
 * @B: the array to copy to a sorted version of the desired sequence
 * @start: offset to copy @A from
 * @mid: offset to allow for sliting the arrays into two
 * @end: the size of @A for which to stop copying
 * Return: void
 */
void merge_array(int *A, int start, int mid, int end, int *B)
{
	int i_start = start;
	int j_mid = mid;
	int k;

	printf("Merging...\n[left]: ");
	print_array(A + start, mid - start);
	printf("[right]: ");
	print_array(A + mid, end - mid);

	for (k = start; k < end; k++)
	{
		if (i_start < mid && (j_mid >= end || A[i_start] <= A[j_mid]))
			B[k] = A[i_start++];
		else
			B[k] = A[j_mid++];
	}
	printf("[Done]: ");
	print_array(B + start, end - start);

}
