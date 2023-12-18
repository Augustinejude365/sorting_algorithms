#include "sort.h"

/**
 * partition - A function partitions the array of integers.
 * @array: the array of integers to be sorted.
 * @low: low position of the array.
 * @high: high position of the array.
 * @size: The array size.
 * Return: integer index.
 */
int partition(int *array, int low, int high, size_t size)
{
	int k = low - 1, temp;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			k++;
			if (k < j)
			{
				temp = array[k];
				array[k] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[k + 1] > array[high])
	{
		temp = array[k + 1];
		array[k + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (k + 1);
}

/**
 * qs - A function that sorts integers in recursion.
 * @array: the array of integers to be sorted.
 * @low: low position of the array.
 * @high: high position of the array.
 * @size: size of the array.
 * Return: void always.
 */
void qs(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		qs(array, low, pivot - 1, size);
		qs(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - A function that sorts array of integer with Quick
 * sorting algorithm.
 * @array: the array of integers to be sorted.
 * @size: The array size.
 * Return: Void.
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
