#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: The pointer to the array
 * @size: The size of the array
 * Return: Nothing (void function)
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j, temp;

	if (array == NULL || array[1] == '\0')
	{
		return;
	}
	if (array[2] == '\0' || size == 1)
	{
		if (array[0] > array[1])
		{
			temp = array[1];
			array[1] = array[0];
			array[0] = temp;
			print_array(array, size);
		}
		return;
	}

	gap = 1;
	while (gap < (int)size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
