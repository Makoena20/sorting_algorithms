#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array = NULL;
    int *output = NULL;
    size_t i, max = 0;

    if (size < 2)
        return;

    for (i = 0; i < size; i++) {
        if ((size_t)array[i] > max)
            max = array[i];
    }

    count_array = malloc(sizeof(int) * (max + 1));
    if (!count_array)
        return;

    output = malloc(sizeof(int) * size);
    if (!output) {
        free(count_array);
        return;
    }

    for (i = 0; i <= max; i++)
        count_array[i] = 0;

    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    printf("%d", count_array[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", count_array[i]);
    printf("\n");

    for (i = 1; i <= max; i++)
        count_array[i] += count_array[i - 1];

    for (i = 0; i < size; i++) {
        output[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count_array);
    free(output);
}

