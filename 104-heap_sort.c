#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Perform sift-down operation on a heap
 * @array: Array representing the heap
 * @size: Size of the array
 * @root: Index of the root of the subtree to sift down
 * @total_size: Total size of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t total_size)
{
    size_t max, left_child, right_child;
    int temp;

    while ((left_child = 2 * root + 1) < total_size)
    {
        max = left_child;
        right_child = left_child + 1;
        if (right_child < total_size && array[right_child] > array[max])
            max = right_child;
        if (array[root] >= array[max])
            break;
        temp = array[root];
        array[root] = array[max];
        array[max] = temp;
        print_array(array, size);
        root = max;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
    int temp;
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2 - 1; (int)i >= 0; i--)
        sift_down(array, size, i, size);

    for (i = size - 1; i > 0; i--)
    {
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        print_array(array, size);
        sift_down(array, size, 0, i);
    }
}

