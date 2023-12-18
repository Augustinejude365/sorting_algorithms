#include "sort.h"

/**
 * swap_ints - A function that swaps two integers in an array.
 * @a: The first integer to be swaped.
 * @b: The second integer to be swaped.
 * Return: Void.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - A function that sorts an array of integers in
 * ascending order using the shell sorting algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: This function Uses the Knuth interval sequence.
 * Return: Void upon success.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size; gap = 3 * gap + 1)
		;

	while (gap > 0)
	{
		gap /= 3;

		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
