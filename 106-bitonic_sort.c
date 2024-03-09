#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - merge a bitonic sequence in a specific order
 * @array: array to be sorted
 * @low: start index of the sequence
 * @size: size of the sequence to be merged
 * @dir: direction of the merge (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
                print_array(array, size);
            }
        }

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - recursively sort a bitonic sequence
 * @array: array to be sorted
 * @low: start index of the sequence
 * @size: size of the sequence
 * @dir: direction of the merge (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2;

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);
        bitonic_merge(array, low, size, dir);
    }
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, 0, size, 1);
}

