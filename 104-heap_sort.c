#include "sort.h"
#include <stdio.h>
/**
 * number_sw - function to swap nums
 * @ay: array inp
 * @f: ind num one
 * @d: ind num tow
 * Return: void
 */
void number_sw(int *ay, int f, int d)
{
	ay[f] = ay[f] + ay[d];
	ay[d] = ay[f] - ay[d];
	ay[f] = ay[f] - ay[d];
}

/**
 * hp_rc_func - build max tree is heap
 * @arr: array ind
 * @i: number of ind
 * @sz: array lenght
 * @tml: array limit
 * Return: void
 */
void hp_rc_func(int *arr, int i, size_t sz, int tml)
{
	int bg;
	int f3;

	f3 = i * 2;

	if (f3 + 2 < tml)
	{
		hp_rc_func(arr, f3 + 1, sz, tml);
		hp_rc_func(arr, f3 + 2, sz, tml);
	}

	if (f3 + 1 >= tml)
		return;

	if (f3 + 2 < tml)
		bg = (arr[f3 + 1] > arr[f3 + 2]) ? (f3 + 1) : (f3 + 2);
	else
		bg = f3 + 1;

	if (arr[i] < arr[bg])
	{
		number_sw(arr, i, bg);
		print_array(arr, sz);
		hp_rc_func(arr, bg, sz, tml);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending..
 * @array: input array
 * @size: size of the array
 * amine mohamed and salma abzou
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t tml;

	if (!array || size == 0)
		return;

	i = 0;
	tml = size;

	while (tml > 1)
	{
		hp_rc_func(array, i, size, tml);
		if (array[i] >= array[tml - 1])
		{
			number_sw(array, i, tml - 1);
			print_array(array, size);
		}
			tml--;
	}
}
