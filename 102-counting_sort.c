#include "sort.h"
/**
 * counting_sort -This sorts an array of integers
 * @array: array
 * @size: size
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int *buffer, *a;
	int m, j;

	if (size < 2)
		return;

	for (m = j = 0; j < (int)size; j++)
		if (array[j] > m)
			m = array[j];

	buffer = malloc(sizeof(int) * (m + 1));
	if (!buffer)
		return;

	for (j = 0; j <= m; j++)
		buffer[j] = 0;
	for (j = 0; j < (int)size; j++)
		buffer[array[j]] += 1;
	for (j = 1; j <= m; j++)
		buffer[j] += buffer[j - 1];

	print_array(buffer, (m + 1));
	a = malloc(sizeof(int) * (size + 1));

	if (!a)
	{
		free(buffer);
		return;
	}
	for (j = 0; j < (int)size; j++)
	{
		a[buffer[array[j]] - 1] = array[j];
		buffer[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = a[j];

	free(buffer);
	free(a);
}
