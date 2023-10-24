#ifndef _SORT_
#define _SORT_

#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: the int
 * @prev: before pointer
 * @next: next pointer
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void srtQuick(int *a, int lw, int higher, int sz);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void sortShell(int *a, int sz, int m);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
#endif
