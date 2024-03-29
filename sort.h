#ifndef SORT_H
#define SORT_H

#include <stdio.h>

/* Function prototypes */
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);


#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);

void print_array(const int *array, size_t size);
void selection_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void quick_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void shell_sort(int *array, size_t size);

void print_list(const listint_t *list);
void cocktail_sort_list(listint_t **list);

void print_array(const int *array, size_t size);
void counting_sort(int *array, size_t size);


/* Provided print_array function */
void print_array(const int *array, size_t size);

/* Function prototype for counting sort */
void counting_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void bitonic_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void counting_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, size_t size, int low, int high);
void swap(int *a, int *b);

#endif /* SORT_H */

