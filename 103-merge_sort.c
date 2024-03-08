#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int *left, int left_size, int *right, int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, size_t size) {
    if (size > 1) {
        int mid = size / 2;
        int *left = array;
        int *right = array + mid;
        int left_size = mid;
        int right_size = size - mid;

        merge_sort(left, left_size);
        merge_sort(right, right_size);

        printf("Merging...\n[left]: ");
        print_array(left, left_size);
        printf("[right]: ");
        print_array(right, right_size);

        merge(array, left, left_size, right, right_size);

        printf("[Done]: ");
        print_array(array, size);
    }
}
