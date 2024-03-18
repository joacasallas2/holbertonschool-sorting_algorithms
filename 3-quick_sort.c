#include "sort.h"

/**
 * quick_sort -  function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The pointer to the array
 * @size: The size of the array
 * Return: Nothing (void function)
 */
void quick_sort(int *array, size_t size)
{
	int pivot, index = 0, aux = 0, j = size - 1, i = 1, indexPivot;

	if (array == NULL || array[1] == '\0')
	{
		return;
	}
	if (array[2] == '\0')
	{
		if (array[0] > array[1])
		{
			aux = array[1];
			array[1] = array[0];
			array[0] = aux;
			print_array(array, size);
		}
		return;
	}

	indexPivot = (int)size - i;
	pivot = array[index];
	j = indexPivot;
	while (j > index)
	{
		if (array[j] < pivot)
		{
			aux = array[j];
			array[j] = array[index];
			array[index] = aux;
			index++;
			j = (int)size - 1;
			print_array(array, size);
		}
		else
		{
			j--;
		}
	}
	if (j == index)
	{
		if (array[j] > pivot)
		{
			aux = array[j];
			array[j] = pivot;
			array[indexPivot] = aux;
			print_array(array, size);
		}
		index++;
		i++;
		indexPivot = size - i;
		pivot = array[indexPivot];
		j = indexPivot - 1;
		while (j > index)
		{
			while (j < indexPivot && array[j] > pivot)
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
				j++;
				print_array(array, size);
			}
			if (j == indexPivot)
			{
				break;
			}
			j--;
		}
	}
	pivot = array[index];
	j = index + 1;
	while (array[j] < pivot)
	{
		aux = array[j];
		array[j] = array[j - 1];
		array[j - 1] = aux;
		j++;
		print_array(array, size);
	}
}
