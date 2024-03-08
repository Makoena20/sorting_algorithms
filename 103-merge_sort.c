#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merge function for merge sort
 * @array: array to merge
 * @left: left index
 * @middle: middle index
 * @right: right index
 * @tmp_array: temporary array to store merged result
 **/
void merge(int *array, size_t left, size_t middle, size_t right, int *tmp_array)
{
    size_t i = left, j = middle, k = 0;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, middle - left);
    printf("[right]: ");
    print_array(array + middle, right - middle);

    while (i < middle && j < right)
    {
        if (array[i] < array[j])
            tmp_array[k++] = array[i++];
        else
            tmp_array[k++] = array[j++];
    }
    while (i < middle)
        tmp_array[k++] = array[i++];
    while (j < right)
        tmp_array[k++] = array[j++];
    for (i = left, k = 0; i < right; ++i, ++k)
        array[i] = tmp_array[k];

    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - recursive merge sort function
 * @array: array to sort
 * @left: left index
 * @right: right index
 * @tmp_array: temporary array to store merged result
 **/
void merge_sort_recursive(int *array, size_t left, size_t right, int *tmp_array)
{
    size_t middle;

    if (right - left <= 1)
        return;

    middle = left + (right - left) / 2;

    merge_sort_recursive(array, left, middle, tmp_array);
    merge_sort_recursive(array, middle, right, tmp_array);
    merge(array, left, middle, right, tmp_array);
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 *              merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
    int *tmp_array;

    if (size < 2 || !array)
        return;

    tmp_array = malloc(size * sizeof(int));
    if (!tmp_array)
        return;

    merge_sort_recursive(array, 0, size, tmp_array);

    free(tmp_array);
}

