#include "sort.h"
/**
 * quick_sort - this function sorts an array using the quick sort algorithm
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	srtQuick(array, 0, size - 1, size);
}
/**
 * srtQuick - this for the quick sort function
 * @a: ary input
 * @lw: first index
 * @higher: last index
 * @sz: arry length
 * Return: void
 */
void srtQuick(int *a, int lw, int higher, int sz)
{
	int tp;
	int b, y, i;

	if (lw < higher)
	{
		b = higher;
		y = lw;
		for (i = lw; i < higher; i++)
		{
			if (a[i] < a[b])
			{
				if (i != y)
				{
					tp = a[i];
					a[i] = a[y];
					a[y] = tp;
					print_array(a, sz);
				}
				y++;
			}
		}
		if (y != b && a[y] != a[b])
		{
			tp = a[y];
			a[y] = a[b];
			a[b] = tp;
			print_array(a, sz);
		}
		srtQuick(a, lw, y - 1, sz);
		srtQuick(a, y + 1, higher, sz);
	}
}
