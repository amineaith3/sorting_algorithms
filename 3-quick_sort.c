#include "sort.h"

void swap_ints(int *var_a, int *var_b);
int lomuto_partition(int *array, size_t size, int lft, int rgt);
void lomuto_sort(int *array, size_t size, int lft, int rgt);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pvt).
 * @array: The array of integers.
 * @size: The size of the array.
 * @lft: The starting index of the subset to order.
 * @rgt: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int lft, int rgt)
{
	int *pvt, abv, blw;

	pvt = array + rgt;
	for (abv = blw = lft; blw < rgt; blw++)
	{
		if (array[blw] < *pvt)
		{
			if (abv < blw)
			{
				swap_ints(array + blw, array + abv);
				print_array(array, size);
			}
			abv++;
		}
	}

	if (array[abv] > *pvt)
	{
		swap_ints(array + abv, pvt);
		print_array(array, size);
	}

	return (abv);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lft: The starting index of the array partition to order.
 * @rgt: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int lft, int rgt)
{
	int part;

	if (rgt - lft > 0)
	{
		part = lomuto_partition(array, size, lft, rgt);
		lomuto_sort(array, size, lft, part - 1);
		lomuto_sort(array, size, part + 1, rgt);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
