#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - A function that Sorts a sub-array of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted sub_array.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 * Return: Void.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t m, l, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (m = front, l = mid; m < mid && l < back; k++)
		buff[k] = (subarr[m] < subarr[l]) ? subarr[m++] : subarr[l++];
	for (; m < mid; m++)
		buff[k++] = subarr[m];
	for (; l < back; l++)
		buff[k++] = subarr[l];
	for (m = front, k = 0; m < back; m++)
		subarr[m] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - A function that Implements the merge
 * sorting algorithm through recursion.
 * @subarr: A sub_array of an array of integers to be sorted.
 * @buff: A buffer where sorted result will be stored.
 * @front: The front index of the sub_array.
 * @back: The back index of the sub_array.
 * Return: Void.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - A function that Sorts an array of integers in
 * ascending order using the merge sorting algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * *
 * Description: This function implements the top-down merge sorting algorithm.
 * Return:Void.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
