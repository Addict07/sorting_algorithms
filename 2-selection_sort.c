#include "sort.h"

/**
 * selection_sort - this func to
 * @array: array of int
 * @size: array size
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int tp;
	size_t n, k, g;

	for (n = 0; n < size; n++)
	{
		g = n;
		for (k = n + 1; k < size; k++)
		{
			if (array[g] > array[k])
				g = k;
		}

		if (n != g)
		{
			tp = array[n];
			array[n] = array[g];
			array[g] = tp;
			print_array(array, size);
		}
	}
}
