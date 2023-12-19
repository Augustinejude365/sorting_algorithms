#include "sort.h"

/**
 * swap_ints - A function that swaps two integers in an array.
 * @a: The first integer to be swaped.
 * @b: The second integer to be swaped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - A function that orders a subset of an array of
 * integers according to the hoare partition scheme.
 * @array: The array of integers to be partitioned.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The last index of the subset to order.
 * Return: The final partition index.
 * Description: This function uses the last element of the
 * partition as the pivot/focus and prints the array after each swap
 * of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int focus, above, below;

	focus = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < focus);
		do {
			below--;
		} while (array[below] > focus);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - A function that implements the quicksort algorithm
 * through recursion.
 * @array: An array of integers to be sorted.
 * @size: The size of the array tp be sorted.
 * @left: The starting index of the array to be partitioned to order.
 * @right: The ending index of the array to be partitioned to order.
 * Description: This function uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int frag;

	if (right - left > 0)
	{
		frag = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, frag - 1);
		hoare_sort(array, size, frag, right);
	}
}

/**
 * quick_sort_hoare - A function that sorts an array of integers in
 * ascending order, using the quicksort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array to be sorted.
 * Description: This function uses the Hoare partition scheme snd
 * prints the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
