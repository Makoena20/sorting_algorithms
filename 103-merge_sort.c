#include "sort.h"
#include <stdlib.h>

void merge(int *array, size_t l, size_t m, size_t r);
void merge_sort_helper(int *array, size_t l, size_t r);

/**
 * merge_sort - sorts an array of integers in ascending order using
 *              the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_helper(array, 0, size - 1);
}

/**
 * merge_sort_helper - recursive function to perform merge sort
 * @array: array to be sorted
 * @l: left index
 * @r: right index
 */
void merge_sort_helper(int *array, size_t l, size_t r)
{
    if (l < r)
    {
        size_t m = l + (r - l) / 2;
        merge_sort_helper(array, l, m);
        merge_sort_helper(array, m + 1, r);
        merge(array, l, m, r);
    }
}

/**
 * merge - merges two sub-arrays of array
 * @array: array to be sorted
 * @l: left index
 * @m: middle index
 * @r: right index
 */
void merge(int *array, size_t l, size_t m, size_t r)
{
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;
    int *L = malloc(sizeof(int) * n1);
    int *R = malloc(sizeof(int) * n2);

    if (L == NULL || R == NULL)
        return;

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

