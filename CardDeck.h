/**
 * @file CardDeck.h
 * @brief Header file for CardDeck data type
 * @author Assignment 2 Group
 * @date 2025-11-17
 *
 * This file contains the definition of the CardDeck data type, which
 * represents a dynamic collection of playing cards. The CardDeck uses
 * dynamic memory allocation to support any number of cards.
 *
 * The CardDeck structure contains:
 * - cards: A dynamically allocated array of Card structures
 * - size: The current number of cards in the deck
 * - capacity: The maximum number of cards the deck can hold before reallocation
 *
 * The CardDeck supports various operations including:
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
	Card* cards;     /**< Dynamically allocated array of cards */
	int size;        /**< Current number of cards in the deck */
	int capacity;    /**< Maximum capacity before reallocation needed */
} CardDeck;

/**
 * @brief Create a new empty card deck
 *
 * Allocates memory for a new CardDeck with initial capacity.
 *
 * @return Pointer to newly created CardDeck
 */
CardDeck* createCardDeck(void);

/**
 * @brief Create a new card deck with specified number of standard packs
 *
 * Creates a deck containing the specified number of complete 52-card packs.
 * Each pack contains all combinations of suits and ranks.
 *
 * @param numPacks Number of 52-card packs to include
 * @return Pointer to newly created and initialized CardDeck
 */
CardDeck* createCardDeckWithPacks(int numPacks);

/**
 * @brief Destroy a card deck and free its memory
 *
 * Frees all memory associated with the deck, including the cards array
 * and the deck structure itself.
 *
 * @param deck Pointer to the deck to destroy
 */
void destroyCardDeck(CardDeck* deck);

/**
 * @brief Add a card to the top of the deck
 *
 * Adds a card to the end of the deck (top position). Automatically
 * expands the deck capacity if needed.
 *
 * @param deck Pointer to the deck
 * @param card Card to add
 */
void addCardToTop(CardDeck* deck, Card card);

/**
 * @brief Remove and return the top card from the deck
 *
 * Removes the last card (top of deck) and returns it. The deck size
 * is decreased by one.
 *
 * @param deck Pointer to the deck
 * @return The card that was removed from the top
 */
Card removeCardFromTop(CardDeck* deck);

/**
 * @brief Remove a card at a specific index
 *
 * Removes the card at the specified index (0-based) and returns it.
 * All cards after this position are shifted down.
 *
 * @param deck Pointer to the deck
 * @param index Index of the card to remove (0-based)
 * @return The card that was removed
 */
Card removeCardAtIndex(CardDeck* deck, int index);

/**
 * @brief Get the top card without removing it
 *
 * Returns a copy of the top card without modifying the deck.
 *
 * @param deck Pointer to the deck
 * @return The top card
 */
Card peekTopCard(CardDeck* deck);

/**
 * @brief Check if the deck is empty
 *
 * @param deck Pointer to the deck
 * @return 1 if deck is empty, 0 otherwise
 */
int isDeckEmpty(CardDeck* deck);

/**
 * @brief Get the number of cards in the deck
 *
 * @param deck Pointer to the deck
 * @return Number of cards currently in the deck
 */
int getDeckSize(CardDeck* deck);

/**
 * @brief Shuffle the deck using random card selection
 *
 * Implements the shuffling algorithm specified in the assignment:
 * Creates a new deck and repeatedly selects random cards from the
 * original deck to build the shuffled deck.
 *
 * @param deck Pointer to the deck to shuffle
 */
void shuffleDeck(CardDeck* deck);

/**
 * @brief Sort the deck using insertion sort
 *
 * Sorts cards first by suit (Club < Spade < Heart < Diamond),
 * then by rank within each suit (Two < Three < ... < Ace).
 * Uses insertion sort algorithm.
 *
 * @param deck Pointer to the deck to sort
 */
void sortDeck(CardDeck* deck);

/**
 * @brief Print all cards in the deck
 *
 * Prints all cards in the deck on a single line, separated by spaces.
 *
 * @param deck Pointer to the deck to print
 */
void printDeck(CardDeck* deck);

/**
 * @brief Find index of first card matching the given card
 *
 * Searches for a card that matches the given card in either suit or rank.
 *
 * @param deck Pointer to the deck to search
 * @param card Card to match against
 * @return Index of first matching card, or -1 if no match found
 */
int findMatchingCard(CardDeck* deck, Card card);

/**
 * @brief Transfer all cards from source deck to destination deck
 *
 * Moves all cards from the source deck to the destination deck.
 * The source deck becomes empty after this operation.
 *
 * @param source Pointer to source deck
 * @param dest Pointer to destination deck
 */
void transferCards(CardDeck* source, CardDeck* dest);

#endif
