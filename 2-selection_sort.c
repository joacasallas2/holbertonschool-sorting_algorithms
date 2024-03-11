#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The pointer to the array
 * @size: the size of the array
 * Return: Nothing (void function)
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, index = 0, flag = 0;

	if (array == NULL || array[1] == '\0')
	{
		return;
	}
	if (array[2] == '\0')
	{
		if (array[0] > array[1])
		{
			min = array[1];
			array[1] = array[0];
			array[0] = min;
			print_array(array, size);
		}
		return;
	}
	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index = j;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			array[index] = array[i];
			array[i] = min;
			print_array(array, size);
		}
		flag = 0;
	}
}
