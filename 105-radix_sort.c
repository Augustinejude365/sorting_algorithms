#include "sort.h"

/**
 * get_max - A function thst fetches the maximum value in an array of integers.
 * @array: An array of integers under consideration.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, g;

	for (max = array[0], g = 1; g < size; g++)
	{
		if (array[g] > max)
			max = array[g];
	}

	return (max);
}

/**
 * radix_counting_sort - A function that sorts the significant
 * digits of an array of integers in ascending order employing the
 * counting sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @sig: The significant digit to be sorted.
 * @buff: A buffer for storing the sorted array.
 * Return: Void.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int kount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t g;

	for (g = 0; g < size; g++)
		kount[(array[g] / sig) % 10] += 1;

	for (g = 0; g < 10; g++)
		kount[g] += kount[g - 1];

	for (g = size - 1; (int)g >= 0; g--)
	{
		buff[kount[(array[g] / sig) % 10] - 1] = array[g];
		kount[(array[g] / sig) % 10] -= 1;
	}

	for (g = 0; g < size; g++)
		array[g] = buff[g];
}

/**
 * radix_sort - A function that sorts an array of integers in
 * ascending order employing the radix sorting algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * Description: This function implements the LSD radix sort
 * algorithm and prints the array after each significant digit increase.
 * Return: Void.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
