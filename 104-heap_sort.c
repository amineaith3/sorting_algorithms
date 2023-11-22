#include "sort.h"

void swap_ints(int *var_a, int *var_b);
void max_heapify(int *array, size_t size, size_t base, size_t rooted);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @var_a: The first integer to swap.
 * @var_b: The second integer to swap.
 */
void swap_ints(int *var_a, int *var_b)
{
	int tmp;

	tmp = *var_a;
	*var_a = *var_b;
	*var_b = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @rooted: The rooted node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t rooted)
{
	size_t lft, rgt, big;

	lft = 2 * rooted + 1;
	rgt = 2 * rooted + 2;
	big = rooted;

	if (lft < base && array[lft] > array[big])
		big = lft;
	if (rgt < base && array[rgt] > array[big])
		big = rgt;

	if (big != rooted)
	{
		swap_ints(array + rooted, array + big);
		print_array(array, size);
		max_heapify(array, size, base, big);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
