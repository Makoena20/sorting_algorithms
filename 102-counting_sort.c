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
    int *count, *output;
    size_t i, max = 0;

    if (size < 2)
        return;

    /* Find the maximum element in the array */
    for (i = 0; i < size; i++) {
        if ((size_t)array[i] > max)
            max = array[i];
    }

    /* Allocate memory for count and output arrays */
    count = malloc((max + 1) * sizeof(int));
    output = malloc(size * sizeof(int));

    if (count == NULL || output == NULL) {
        free(count);
        free(output);
        return;
    }

    /* Initialize count array with 0 */
    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Count occurrences of each element in array */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Print count array */
    printf("%d", count[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", count[i]);
    printf("\n");

    /* Adjust count array to reflect the position of elements in output */
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Place elements in output array using count array */
    for (i = size - 1; i < size; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy sorted elements from output array to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Free dynamically allocated memory */
    free(count);
    free(output);
}

