#include "sort.h"
#include <stdlib.h>

/**
 *  * counting_sort - Sorting arr with the Counting sort alg
 *   * @array: The Arr
 *    * @size: Size of arr
 *     */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array;
	int max_value, current_num;
	size_t i;

	if (size < 2 || !array)
		return;

	max_value = array[0];
	for (i = 1; i < size; i++)
		max_value = (array[i] > max_value) ? array[i] : max_value;

	count_array = malloc(sizeof(int) * (max_value + 1));
	output_array = malloc(sizeof(int) * size);

	for (i = 0; i <= (size_t)max_value; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]] += 1;

	for (i = 1; i <= (size_t)max_value; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max_value + 1);

	for (i = 0; i < size; i++)
	{
		current_num = array[i];
		output_array[count_array[current_num] - 1] = current_num;
		count_array[current_num]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(output_array);
	free(count_array);
}
