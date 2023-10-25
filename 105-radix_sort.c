#include "sort.h"
/**
 * radix_sort - sorts an array of integers in ascending..
 * @array: arr inp
 * @size: arr size
 */
void radix_sort(int *array, size_t size)
{
	int fg = 1, num = 10;
	size_t j, h;

	if (!array || size == 1)
		return;
	while (fg)
	{
		fg = 0;
		for (j = 1, h = 1; j <  size; j++, h++)
		{
			if ((array[j - 1] % (num * 10)) / ((num * 10) / 10) > 0)
				fg = 1;
			if (((array[j - 1] % num) / (num / 10)) > ((array[j] % num) / (num / 10)))
			{
				array[j - 1] = array[j - 1] + array[j];
				array[j] = array[j - 1] - array[j];
				array[j - 1] = array[j - 1] - array[j];
				if ((j - 1) > 0)
					j = j - 2;
			}
		}
		print_array(array, size);
		num = num * 10;
	}
}
