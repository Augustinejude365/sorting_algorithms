#include "sort.h"
#include <stdio.h>

/**
 * swap - A function that swaps two integers in ascending or descending order.
 * @arr: An array of integers to be swaped.
 * @item1: The first value.
 * @item2: The second value.
 * @order: The flow of the swap- 1: ascending order, 0 descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}
/**
 * merge - A function that merges an array of integers into bitonic
 * sequences recursively in ascending or descending order.
 * @arr: The Array of integers to be merged.
 * @low: The first element in the array.
 * @nelemnt: The number of elements in the array.
 * @order: The flow of sorting, 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int mid, g;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (g = low; g < low + mid; g++)
			swap(arr, g, g + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * bitonicsort - A function that implements bitonic sort algorithm
 * @arr: An Array of integers to be sorted.
 * @low: The first element in the array.
 * @nelemnt: The number of elements in the array.
 * @order: Flow of the sorting- 1: ascending order, 0 descending order
 * @size: The size of the array
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		mid = nelemnt / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}
/**
 * bitonic_sort - A function that prepares the platform for bitonic
 * sorting algorithm.
 * @array: The Array of integers to be sorted.
 * @size: The size of the array to be sorted.
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
