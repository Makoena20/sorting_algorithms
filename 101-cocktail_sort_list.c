#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order using Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start = NULL;
    listint_t *end = NULL;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        for (start = *list; start->next != end; start = start->next)
        {
            if (start->n > start->next->n)
            {
                swap_nodes(list, start, start->next);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end = start;

        for (start = start->prev; start != NULL; start = start->prev)
        {
            if (start->n > start->next->n)
            {
                swap_nodes(list, start, start->next);
                print_list(*list);
                swapped = 1;
            }
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node_a: First node to swap
 * @node_b: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
    if (node_a == NULL || node_b == NULL)
        return;

    if (node_a->prev != NULL)
        node_a->prev->next = node_b;
    else
        *list = node_b;

    if (node_b->next != NULL)
        node_b->next->prev = node_a;

    node_a->next = node_b->next;
    node_b->prev = node_a->prev;
    node_a->prev = node_b;
    node_b->next = node_a;
}
