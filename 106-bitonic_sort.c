#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - Merge phase of Bitonic Sort
 * @array: Array to be sorted
 * @low: Starting index of the subarray to be sorted
 * @count: Size of the subarray to be sorted
 * @dir: Sorting direction (UP or DOWN)
 * @size: Total size of the array
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                printf("Result [%lu/%lu] (%s):\n", count, size, dir == 1 ? "UP" : "DOWN");
                print_array(array, size);
            }
        }

        bitonic_merge(array, low, k, dir, size);
        bitonic_merge(array, low + k, k, dir, size);
    }
}

/**
 * bitonic_sort_recursive - Recursive phase of Bitonic Sort
 * @array: Array to be sorted
 * @low: Starting index of the subarray to be sorted
 * @count: Size of the subarray to be sorted
 * @dir: Sorting direction (UP or DOWN)
 * @size: Total size of the array
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir, size_t size)
{
    if (count > 1)
    {
        size_t k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n", count, size, dir == 1 ? "UP" : "DOWN");
        print_array(array + low, count);

        bitonic_sort_recursive(array, low, k, 1, size);
        bitonic_sort_recursive(array, low + k, k, 0, size);
        bitonic_merge(array, low, count, dir, size);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array != NULL && size > 1)
    {
        bitonic_sort_recursive(array, 0, size, 1, size);
    }
}

