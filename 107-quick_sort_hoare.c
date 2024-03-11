#include <stdio.h>
#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick sort algorithm (Hoare partition scheme)
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_partition(array, size, 0, size - 1);
}

/**
 * hoare_partition - Partitions an array into smaller sub-arrays
 *                   according to the Hoare partition scheme
 * @array: The array to partition
 * @size: The size of the array
 * @low: The starting index of the partition to sort
 * @high: The ending index of the partition to sort
 *
 * Return: The index of the partitioning element
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * swap - Swaps two integers
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

