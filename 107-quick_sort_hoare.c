#include "sort.h"

void integerSw(int *alpha, int *B);
int partHr(int *arr, size_t size, int lt, int rt);
void sortHr(int *arr, size_t sz, int lt, int rt);
void quick_sort_hoare(int *array, size_t size);

/**
 * integerSw - function that swap all element of array
 * @alpha: ele num one
 * @B: ele num tow
 * Return: void
 */
void integerSw(int *alpha, int *B)
{
	int tp;

	tp = *alpha;
	*alpha = *B;
	*B = tp;
}

/**
 * partHr - this function to order array
 * @arr: int array.
 * @size: array lenght.
 * @lt: first index.
 * @rt: last index.
 * Return: return int.
 */
int partHr(int *arr, size_t size, int lt, int rt)
{
	int tpv, bve, blw;

	tpv = arr[rt];
	for (bve = lt - 1, blw = rt + 1; bve < blw;)
	{
		do {
			bve++;
		} while (arr[bve] < tpv);
		do {
			blw--;
		} while (arr[blw] > tpv);

		if (bve < blw)
		{
			integerSw(arr + bve, arr + blw);
			print_array(arr, size);
		}
	}

	return (bve);
}

/**
 * sortHr - to implement quick sort algo.
 * @arr: array of int.
 * @sz: array lenght.
 * @lt: first index.
 * @rt: second index.
 * Return: void
 */
void sortHr(int *arr, size_t sz, int lt, int rt)
{
	int p_r_t;

	if (rt - lt > 0)
	{
		p_r_t = partHr(arr, sz, lt, rt);
		sortHr(arr, sz, lt, p_r_t - 1);
		sortHr(arr, sz, p_r_t, rt);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * @array: int array.
 * @size: array lenght.
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sortHr(array, size, 0, size - 1);
}
