#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "deck.h"

/**
 * compare_cards - Compare two cards
 * @card_a: First card
 * @card_b: Second card
 *
 * Return: Difference in card values
 */
static int compare_cards(const deck_node_t *card_a, const deck_node_t *card_b)
{
    int value_diff = strcmp(card_a->card->value, card_b->card->value);
    
    if (value_diff != 0)
        return value_diff;
    return (card_a->card->kind - card_b->card->kind);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *curr, *next;
    int swapped;
    
    if (deck == NULL || *deck == NULL)
        return;
    
    do {
        swapped = 0;
        curr = *deck;
        
        while (curr->next != NULL) {
            next = curr->next;
            
            if (compare_cards(curr, next) > 0) {
                if (curr->prev == NULL) {
                    *deck = next;
                } else {
                    curr->prev->next = next;
                }
                next->prev = curr->prev;
                curr->next = next->next;
                next->next = curr;
                curr->prev = next;
                
                if (curr->next != NULL)
                    curr->next->prev = curr;
                
                swapped = 1;
            } else {
                curr = curr->next;
            }
        }
    } while (swapped);
}

