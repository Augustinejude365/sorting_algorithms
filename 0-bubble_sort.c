#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers.
 * @array: the array to be sorted.
 * @size: the size of the array.
 * Return: upon success, void.
 */
void bubble_sort(int *array, size_t size)
{
	size_t k, j;
	int g;

	for (k = 1; k < size; k++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				g = array[j];
				array[j] = array[j + 1];
				array[j + 1] = g;
				print_array(array, size);
			}
		}
	}
}
