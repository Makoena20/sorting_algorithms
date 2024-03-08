#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Performs the sift-down operation on a heap
 * @array: Array to be sorted
 * @size: Size of the array
 * @root: Index of the root of the heap
 * @end: Index marking the end of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t max = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < end && array[left] > array[max])
        max = left;

    if (right < end && array[right] > array[max])
        max = right;

    if (max != root)
    {
        swap(&array[root], &array[max]);
        print_array(array, size);
        sift_down(array, size, max, end);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int i;

    for (i = (int)size / 2 - 1; i >= 0; i--)
        sift_down(array, size, (size_t)i, size);

    for (i = (int)size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, size, 0, (size_t)i);
    }
}
