#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Utility function to get the maximum element from an array
 * @array: The array to find the maximum element from
 * @size: The size of the array
 * Return: The maximum element in the array
 */
int getMax(int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * countSort - A function to do counting sort of array based on the digit represented by exp.
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The exponent representing the significant digit
 */
void countSort(int *array, size_t size, int exp) {
    int output[size]; // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the output array to array[], so that array[] now contains sorted numbers according to the current digit
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    // Find the maximum number to know number of digits
    int max = getMax(array, size);

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(array, size, exp);
        print_array(array, size);
    }
}

