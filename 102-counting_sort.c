#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - A finction that Sorts an  array of integers
 * with the Counting sort algorithm.
 * @array: The Array to be sorted.
 * @size: Size of the array.
 * Return: Void.
 */
void counting_sort(int *array, size_t size)
{
	int *kount_array, *output_array;
	int max_value, kurent_num;
	size_t j;

	if (size < 2 || !array)
		return;

	max_value = array[0];
	for (j = 1; j < size; j++)
		max_value = (array[j] > max_value) ? array[j] : max_value;

	kount_array = malloc(sizeof(int) * (max_value + 1));
	output_array = malloc(sizeof(int) * size);

	for (j = 0; j <= (size_t)max_value; j++)
		kount_array[j] = 0;

	for (j = 0; j < size; j++)
		kount_array[array[j]] += 1;

	for (j = 1; j <= (size_t)max_value; j++)
		kount_array[j] += kount_array[j - 1];

	print_array(kount_array, max_value + 1);

	for (j = 0; j < size; j++)
	{
		kurent_num = array[j];
		output_array[kount_array[kurent_num] - 1] = kurent_num;
		kount_array[kurent_num]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output_array[j];

	free(output_array);
	free(kount_array);
}
