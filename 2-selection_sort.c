#include "sort.h"

/**
 * selection_sort - A function that Sorts an array with sort algorithm.
 * @array: The array
 * @size: elements in the @array.
 */
void selection_sort(int *array, size_t size)
{
	size_t cur_indx, comp_indx, min_indx, temp, swap_flag;

	if (array == NULL)
		return;

	for (cur_indx = 0; cur_indx < size; cur_indx++)
	{
		for (min_indx = cur_indx, comp_indx = cur_indx;
			comp_indx < size; comp_indx++)
		{
			if (array[comp_indx] < array[min_indx])
			{
				min_indx = comp_indx;
				swap_flag = 1;
			}
		}
		if (swap_flag == 1)
		{
			temp = array[min_indx];
			array[min_indx] = array[cur_indx];
			array[cur_indx] = temp;
			print_array(array, size);
			swap_flag = 0;
		}
	}
}
