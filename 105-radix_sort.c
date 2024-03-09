#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_max - Get the maximum element from the array
 * @array: The array to search
 * @size: The size of the array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * count_sort - Sort the array based on a specific digit
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The exponent of the current digit
 */
void count_sort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};
    size_t i;

    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; (int)i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - Sorts an array of integers using LSD Radix Sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max = get_max(array, size);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        count_sort(array, size, exp);
    }
}

