#include "sort.h"

void swap_ints(int *var_a, int *var_b);
void bitonic_merge(int *array, size_t size, size_t strt, size_t sequ,
		char flw);
void bitonic_seq(int *array, size_t size, size_t strt, size_t sequ, char flw);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sort a bitonic sequ inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @strt: The starting index of the sequ in array to sort.
 * @sequ: The size of the sequ to sort.
 * @flw: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t strt, size_t sequ,
		char flw)
{
	size_t i, jump = sequ / 2;

	if (sequ > 1)
	{
		for (i = strt; i < strt + jump; i++)
		{
			if ((flw == UP && array[i] > array[i + jump]) ||
			    (flw == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, strt, jump, flw);
		bitonic_merge(array, size, strt + jump, jump, flw);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequ.
 * @array: An array of integers.
 * @size: The size of the array.
 * @strt: The starting index of a block of the building bitonic sequ.
 * @sequ: The size of a block of the building bitonic sequ.
 * @flw: The direction to sort the bitonic sequ block in.
 */
void bitonic_seq(int *array, size_t size, size_t strt, size_t sequ, char flw)
{
	size_t cut = sequ / 2;
	char *str = (flw == UP) ? "UP" : "DOWN";

	if (sequ > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequ, size, str);
		print_array(array + strt, sequ);

		bitonic_seq(array, size, strt, cut, UP);
		bitonic_seq(array, size, strt + cut, cut, DOWN);
		bitonic_merge(array, size, strt, sequ, flw);

		printf("Result [%lu/%lu] (%s):\n", sequ, size, str);
		print_array(array + strt, sequ);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
