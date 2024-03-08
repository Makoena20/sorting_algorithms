#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (size_t i = 0; i <= max; i++)
        count[i] = 0;

    for (size_t i = 0; i < size; i++)
        count[array[i]]++;

    printf("%d", count[0]);
    for (size_t i = 1; i <= max; i++)
        printf(", %d", count[i]);
    printf("\n");

    size_t j = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            array[j++] = i;
            count[i]--;
        }
    }

    free(count);
}

