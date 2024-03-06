#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers
 *
 * @list: Pointer to the head of the list
 */
void print_list(const listint_t *list)
{
    const listint_t *temp = list;

    while (temp)
    {
        printf("%d", temp->n);
        temp = temp->next;
        if (temp)
            printf(", ");
    }
    printf("\n");
}

