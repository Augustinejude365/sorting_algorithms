#ifndef _SORT_H_
#define _SORT_H_

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 * *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void qs(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
;
void bitonicsort(int arr[], int low, int nelemnt, int order, int size);
void radix_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void merge(int arr[], int low, int nelemnt, int order);
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
char flow);
void swap(int arr[], int item1, int item2, int order);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node(listint_t *node_a, listint_t *node_b, listint_t **list);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
	size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);

#endif /* _SORT_H_ (Header file) */
