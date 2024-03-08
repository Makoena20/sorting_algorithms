#include "sort.h"
#include <stdio.h>

/**
 * bitonic_merge - Merge the subarrays in a bitonic manner
 * @array: Array to be sorted
 * @low: Starting index of the subarray
 * @count: Number of elements to be merged
 * @dir: Sorting direction (UP or DOWN)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        for (size_t i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                // Swap elements
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                printf("Merging [%lu/%lu] (%s):\n", count, count * 2, dir == 1 ? "UP" : "DOWN");
                print_array(array, count * 2);
            }
        }
        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursively sort a bitonic sequence
 * @array: Array to be sorted
 * @low: Starting index of the subarray
 * @count: Number of elements to be sorted
 * @dir: Sorting direction (UP or DOWN)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        bitonic_sort_recursive(array, low, k, 1); // Sort in ascending order
        bitonic_sort_recursive(array, low + k, k, 0); // Sort in descending order
        bitonic_merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1); // Initially sorting in ascending order
}
