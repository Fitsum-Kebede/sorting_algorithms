#include "sort.h"

/**
* selection_sort - sorts an array using selection sort
* @array: array
* @size: size of array
* Return: void
*/

void selection_sort(int *array, size_t size)
{

	size_t i, j;
	int first = 0, minimum = 0, position = 0;

	if (size < 2)
	{
		return;
	}

	/* One by one move through the array*/
	for (i = 0; i < size; i++)
	{
		if (array[i + 1])
		{
		/*Find the minimum element in the unsorted array*/
			first = array[i];
			minimum = first;
			for (j = i; j < size; j++)
			{
				if (minimum > array[j])
				{
					minimum = array[j];
					position = j;
				}
			}
			if (minimum < first)
			{
				array[i] = minimum;
				array[position] = first;
				print_array(array, size);
			}
		}
	}
}
