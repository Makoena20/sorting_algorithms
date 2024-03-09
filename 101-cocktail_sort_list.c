#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: First node to swap
 * @b: Second node to swap
 */
void swap_nodes(listint_t **a, listint_t **b)
{
    listint_t *temp;

    if (*a != NULL && *b != NULL)
    {
        temp = (*a)->prev;
        (*a)->prev = (*b)->prev;
        (*b)->prev = temp;

        if ((*a)->prev != NULL)
            (*a)->prev->next = *a;
        if ((*b)->prev != NULL)
            (*b)->prev->next = *b;

        temp = *a;
        *a = *b;
        *b = temp;
    }
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start = *list;
    listint_t *end = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;

        while (start->next != end)
        {
            if (start->n > start->next->n)
            {
                swap_nodes(&start, &(start->next));
                if (!start->prev)
                    *list = start;
                print_list(*list);
                swapped = 1;
            }
            else
                start = start->next;
        }

        if (!swapped)
            break;

        swapped = 0;
        end = start;

        while (end->prev != NULL)
        {
            if (end->n < end->prev->n)
            {
                swap_nodes(&(end->prev), &end);
                if (!end->prev)
                    *list = end;
                print_list(*list);
                swapped = 1;
            }
            else
                end = end->prev;
        }

        start = start->prev;
    }
}

