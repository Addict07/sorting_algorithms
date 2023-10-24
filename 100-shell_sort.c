#include "sort.h"
/**
 * shell_sort - This sorts an array...
 * @array: input arrray
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		sortShell(array, size, n);
}
/**
 * sortShell - This is for the function before
 * @a: input
 * @sz: array lenght
 * @m: the intervl
 * Return: void
 */
void sortShell(int *a, int sz, int m)
{
	int tp, i, j;

	for (i = 0; (i + m) < sz; i++)
	{
		for (j = i + m; (j - m) >= 0; j = j - m)
		{
			if (a[j] < a[j - m])
			{
				tp = a[j];
				a[j] = a[j - m];
				a[j - m] = tp;
			}
		}
	}
	print_array(a, sz);
}
