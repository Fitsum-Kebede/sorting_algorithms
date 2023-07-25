#include "sort.h"

/**
 * quick_sort - sort using quick sort algorithm
 * @array: array
 * @size: size of array to sort
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (size < 2 || !array)
		return;
	recursive_sort(array, low, high, size);
}

/**
 * recursive_sort - sort using recursive sort algorithm
 * @array: array
 * @size: size of array to sort
 * @low: starting index of array
 * @high: ending index of array
 * Return: void
 */
void recursive_sort(int *array, int low, int high, size_t size)
{
	int part = 0;

	if (low < high)
	{
		part = partition(array, low, high, size);
		recursive_sort(array, low, part - 1, size);
		recursive_sort(array, part + 1, high, size);
	}
}

/**
 * partition - sort using recursive sort algorithm
 * @array: array
 * @size: size of array to sort
 * @low: starting index of array
 * @high: ending index of array
 * Return: int
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low, j = 0, swap = 0;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			swap = array[j];
			array[j] = array[i];
			array[i] = swap;
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap = array[i];
	array[i] = array[high];
	array[high] = swap;
	if (array[high] != pivot)
		print_array(array, size);
	return (i);
}
