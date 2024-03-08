#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * countingSort - sorts the array based on significant
 *                digit represented by exp.
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The exponent of 10
 */
void countingSort(int *array, size_t size, int exp)
{
    int *output = NULL;
    int count[10] = {0};
    int i;

    output = malloc(sizeof(int) * size);
    if (!output)
        return;

    for (i = 0; i < (int)size; ++i)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (i = (int)size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < (int)size; ++i)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 *              using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (size < 2)
        return;

    max = array[0];
    for (size_t i = 1; i < size; ++i) {
        if (array[i] > max)
            max = array[i];
    }

    for (exp = 1; max / exp > 0; exp *= 10) {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}

