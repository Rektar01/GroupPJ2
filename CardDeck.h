/**
 * @file CardDeck.h
 * @brief Header file for CardDeck 
 * @author assignment  group 2
 * @date 19.11.2025
 *
 * his file contains the  definitions of the fuctions used in the card deck game our team have developed. The game uses
 * dynamic memory allocation to support any number of cards.
 *
 * The structure of our code contains:
 * - cards: A dynamically allocated array of Card structures
 * - size: The current number of cards in the deck
 * - capacity: The maximum number of cards the deck can hold before reallocation
 *
 * The card supports various operations including:
 * - Creating and destroying decks
 * - Adding and removing cards (from top or at specific positions)
 * - Shuffling cards
 * - Sorting cards
 * - Checking if deck is empty
 * - Printing deck contents
 */

#ifndef CARDDECK_H
#define CARDDECK_H

#include "Card.h"

/**
 * @brief Structure representing a deck of cards
 *
 * A CardDeck is a dynamic collection of cards that can grow or shrink
 * as needed. It uses dynamic memory allocation to support any number
 * of cards.
 */
typedef struct {
	Card* cards;     /** dynamically allocated array of cards */
	int size;        /** current number of cards in the deck */
	int capacity;    /** maximum capacity before reallocation needed */
} CardDeck;

/**
 * @brief create a new empty card deck
 *
 * allocates memory for a new CardDeck with initial capacity.
 *
 * @return pointer to newly created CardDeck
 */
CardDeck* createCardDeck(void);

/**
 * @brief create a new card deck with specified number of standard packs
 *
 * creates a deck containing the specified number of  52 card packs.
 * each pack contains all combinations of suits and ranks.
 *
 * @param  number of 52-card packs to be included
 * @return pointer to created and initialised card deck
 */
CardDeck* createCardDeckWithPacks(int numPacks);

/**
 * @brief destroy a card deck and free its memory
 *
 * frees all memory associated with the deck, including the cards array
 * and the deck structure itself.
 *
 * @param pointer to the deck to destroy
 */
void destroyCardDeck(CardDeck* deck);

/**
 * @brief add a card to the top of the deck
 *
 * adds a card to the end of the deck (top). automatically
 * expands the deck capacity if needed.
 *
 * @param pointer to the deck
 * @param card to add
 */
void addCardToTop(CardDeck* deck, Card card);

/**
 * @brief remove and return the top card from the deck
 *
 * removes the last card (at the top of the deck) and returns it. The deck size
 * is decreased by one.
 *
 * @param pointer to the deck
 * @return the card that was removed from the top
 */
Card removeCardFromTop(CardDeck* deck);

/**
 * @brief remove a card at a specific index
 *
 * removes the card at the specified index and returns it.
 * all cards after this position are moved down.
 *
 * @param pointer to the deck
 * @param index of the card to remove
 * @return the card that was removed
 */
Card removeCardAtIndex(CardDeck* deck, int index);

/**
 * @brief get the top card without removing it
 *
 * returns a copy of the top card without modifying the deck.
 *
 * @param pointer to the deck
 * @return the top card
 */
Card peekTopCard(CardDeck* deck);

/**
 * @brief check if the deck is empty
 *
 * @param pointer to the deck
 * @return 1 if deck is empty, 0 otherwise
 */
int isDeckEmpty(CardDeck* deck);

/**
 * @brief get the number of cards in the deck
 *
 * @param pointer to the deck
 * @return number of cards currently in the deck
 */
int getDeckSize(CardDeck* deck);

/**
 * @brief shuffle the deck using random card selection
 *
 * implements the shuffling algorithm specified in the assignment:
 * creates a new deck and repeatedly selects random cards from the
 * original deck to build the shuffled deck.
 *
 * @param pointer to the deck to shuffle
 */
void shuffleDeck(CardDeck* deck);

/**
 * @brief sort the deck using insertion sort
 *
 * sorts cards first by suit (Club < Spade < Heart < Diamond),
 * then by rank within each suit (Two < Three < ... < Ace).
 * Uses insertion sort algorithm.
 *
 * @param pointer to the deck to sort
 */
void sortDeck(CardDeck* deck);

/**
 * @brief print all cards in the deck
 *
 * prints all cards in the deck on a single line with spaces
 *
 * @param pointer to the deck to print
 */
void printDeck(CardDeck* deck);

/**
 * @brief find index of first card matching the given card
 *
 * searches for a card that matches the given card in either suit or rank.
 *
 * @param pointer to the deck to search
 * @param card to match against
 * @return index of first matching card, or -1 if no match found
 */
int findMatchingCard(CardDeck* deck, Card card);

/**
 * @brief transfer all cards from source deck to destination deck
 *
 * moves all cards from the source deck to the destination deck.
 * the source deck becomes empty after this operation.
 *
 * @param pointer to source deck
 * @param pointer to destination deck
 */
void transferCards(CardDeck* source, CardDeck* dest);

#endif
