#include "sort.h"

void swap_ints(int *var_a, int *var_b);
int hoare_partition(int *array, size_t size, int lft, int rgt);
void hoare_sort(int *array, size_t size, int lft, int rgt);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @lft: The starting index of the subset to order.
 * @rgt: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pvt.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int lft, int rgt)
{
	int pvt, abv, blw;

	pvt = array[rgt];
	for (abv = lft - 1, blw = rgt + 1; abv < blw;)
	{
		do {
			abv++;
		} while (array[abv] < pvt);
		do {
			blw--;
		} while (array[blw] > pvt);

		if (abv < blw)
		{
			swap_ints(array + abv, array + blw);
			print_array(array, size);
		}
	}

	return (abv);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lft: The starting index of the array partition to order.
 * @rgt: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int lft, int rgt)
{
	int part;

	if (rgt - lft > 0)
	{
		part = hoare_partition(array, size, lft, rgt);
		hoare_sort(array, size, lft, part - 1);
		hoare_sort(array, size, part, rgt);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme.
 * Prints the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
