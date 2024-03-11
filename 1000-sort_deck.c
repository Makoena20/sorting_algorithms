#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @a: pointer to the first node
 * @b: pointer to the second node
 */
static void swap_nodes(deck_node_t *a, deck_node_t *b)
{
    const card_t *temp = a->card;
    a->card = b->card;
    b->card = temp;
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current, *index;
    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    for (index = *deck; index != NULL; index = index->next)
    {
        for (current = index->next; current != NULL; current = current->next)
        {
            if ((strcmp(index->card->value, current->card->value) > 0) ||
                (strcmp(index->card->value, current->card->value) == 0 &&
                 index->card->kind > current->card->kind))
            {
                swap_nodes(index, current);
            }
        }
    }
}

