#include "sort.h"
#include <stdio.h>
/**
 * bt_print - prints the array
 * @array: array inp
 * @j: index num one
 * @tml: last index
 * Return: void
 * amine mohamed and salma abzou
 */
void bt_print(int *array, int j, int tml)
{
	char *vr_sp;

	for (vr_sp = ""; j < tml; j++)
	{
		printf("%s%d", vr_sp, array[j]);
		vr_sp = ", ";
	}
	printf("\n");
}

/**
 * upStr - func for up mode
 * @arr: arr inp
 * @lwer: ind num one
 * @hier: last ind
 * Return: no return
 */
void upStr(int *arr, int lwer, int hier)
{
	int i, j, mx_num;

	for (i = lwer; i < hier; i++)
	{
		mx_num = i;

		for (j = i + 1; j < hier; j++)
		{
			if (arr[mx_num] > arr[j])
				mx_num = j;
		}

		if (mx_num != i)
		{
			arr[i] = arr[i] + arr[mx_num];
			arr[mx_num] = arr[i] - arr[mx_num];
			arr[i] = arr[i] - arr[mx_num];
		}
	}
}

/**
 * sr_dw - func for down mode
 * @arr: arr inp
 * @lwer: ind num one
 * @hier: last ind
 * Return: void
 */
void sr_dw(int *arr, int lwer, int hier)
{
	int i, j, mx_num;

	for (i = lwer; i < hier; i++)
	{
		mx_num = i;

		for (j = i + 1; j < hier; j++)
		{
			if (arr[mx_num] < arr[j])
				mx_num = j;
		}

		if (mx_num != i)
		{
			arr[i] = arr[i] + arr[mx_num];
			arr[mx_num] = arr[i] - arr[mx_num];
			arr[i] = arr[i] - arr[mx_num];
		}
	}
}

/**
 * func_recv - recursive func
 * @arr: arr inp
 * @lwer: ind num one
 * @hier: last ind
 * @bl: up or down
 * @size: array lenght
 * Return: void
 */
void func_recv(int *arr, int lwer, int hier, int bl, size_t size)
{
	char *opt;

	if (hier - lwer < 2)
		return;

	opt = (bl == 0) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", hier - lwer, size, opt);
	bt_print(arr, lwer, hier);

	if (hier - lwer == 2)
		return;

	func_recv(arr, lwer, (hier + lwer) / 2, 0, size);
	upStr(arr, lwer, (hier + lwer) / 2);
	printf("Result [%d/%ld] (%s):\n", ((hier + lwer) / 2) - lwer, size, "UP");
	bt_print(arr, lwer, (hier + lwer) / 2);

	func_recv(arr, (hier + lwer) / 2, hier, 1, size);
	sr_dw(arr, (hier + lwer) / 2, hier);
	printf("Result [%d/%ld] (%s):\n", hier - ((hier + lwer) / 2), size, "DOWN");
	bt_print(arr, (hier + lwer) / 2, hier);
}

/**
 * bitonic_sort - first function that executes the bitonic_sort
 * algorithm
 *
 * @array: input array
 * @size: lenght of array
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	func_recv(array, 0, size, 0, size);
	upStr(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	bt_print(array, 0, size);
}
