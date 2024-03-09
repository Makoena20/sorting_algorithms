#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two elements in an array and prints the array
 * @array: array of integers
 * @i: index of the first element
 * @j: index of the second element
 */
void swap(int *array, size_t i, size_t j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    printf("Swap: %d, %d\n", array[i], array[j]);
}

/**
 * bitonic_merge - recursively sorts a bitonic sequence in ascending order
 * @array: array of integers
 * @low: starting index of the sequence
 * @size: size of the sequence
 * @dir: direction of sorting
 */
void bitonic_merge(int *array, size_t low, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2;
        size_t i;

        printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
        print_array(array + low, size);
        printf("\n");

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
                swap(array, i, i + k);
        }

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t k = size / 2;

        bitonic_sort(array, k);
        bitonic_sort(array + k, k);

        bitonic_merge(array, 0, size, 1);
    }
}

