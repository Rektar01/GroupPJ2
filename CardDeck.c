/**
 * @file CardDeck.c
 * @brief Implementation of CardDeck data type functions
 * @author Assignment 2 Group
 * @date 20.11.2025
 *
 * This file contains the implementation of all functions for the CardDeck
 * data type, including creation, destruction, manipulation, shuffling,
 * and sorting operations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CardDeck.h"

#define INITIAL_CAPACITY 10

CardDeck* createCardDeck(void)
{
	CardDeck* deck;
	
	deck = (CardDeck*)malloc(sizeof(CardDeck));
	if (deck == NULL) {
		printf("Error: Failed to allocate deck\n");
		exit(1);
	}
	
	deck->cards = (Card*)malloc(INITIAL_CAPACITY * sizeof(Card));
	if (deck->cards == NULL) {
		printf("Error: Failed to allocate cards\n");
		free(deck);
		exit(1);
	}
	
	deck->size = 0;
	deck->capacity = INITIAL_CAPACITY;
	
	return deck;
}
/*
PSEUDOCODE:
1) Initializes the deck as type CardDeck
2) Allocates memory for the three parts of the CardDeck
3) If the deck remains empty
	4) Allocation failed, throws error and exits program
5) Allocates memory for the array of cards within the deck
6) If the card array remains empty
	7) Initialisation failed, throws error and exits program
8) Initialises the current cards in the deck to 0, and the initial capacity to 10
9) Returns the deck
*/

CardDeck* createCardDeckWithPacks(int numPacks)
{
	CardDeck* deck;
	
	deck = createCardDeck();
	
	for (int i = 0; i < numPacks; i++) {
		for (int j = CLUB; j <= DIAMOND; j++) {
			for (int k = TWO; k <= ACE; k++) {
				Card card;
				card.suit = (Suit)s;
				card.rank = (Rank)r;
				addCardToTop(deck, card);
			}
		}
	}
	
	return deck;
}
/*
PSEUDOCODE:
1) Initializes the deck as type CardDeck
2) Allocates memory for an empty deck using createCardDeck
3) Runs 3 for loops, one for the ranks, one for the suits, and another for the number of packs in the deck
	4) Adds a card with the correct rank and suit using addCardToTop for all packs requested
5) Returns the completed deck
*/

void destroyCardDeck(CardDeck* deck)
{
	if (deck != NULL) {
		if (deck->cards != NULL) {
			free(deck->cards);
		}
		free(deck);
	}
}
/*
PSEUDOCODE:
1) If the deck isn't null
	2) If the card array in the deck isn't null
		3) Free the memory allocated for the card array
	4) Free the memory allocated for the deck
*/

void addCardToTop(CardDeck* deck, Card card)
{
	if (deck->size = deck->capacity) {
		int newCapacity;
		Card* newCards;
		
		newCapacity = deck->capacity * 2;
		newCards = (Card*)realloc(deck->cards, newCapacity * sizeof(Card));
		
		if (newCards == NULL) {
			printf("Error: Failed to allocate cards\n");
			exit(1);
		}
		
		deck->cards = newCards;
		deck->capacity = newCapacity;
	}
	
	deck->cards[deck->size] = card;
	deck->size++;
}
/*
PSEUDOCODE:
1) If the deck is at it's capacity
	2) Create a new card array with double the capacity
	3) Allocate the new array's memory and have it contain the cards in the old array
	4) Check the memory is successfully allocated and throw an error otherwise
	5) Set the deck's card array to the new longer card array
	6) Set the deck's capacity to the doubled capacity
7) Adds the card passed to the top of the deck
8) Increases the size of the deck by one for the new card
*/

Card removeCardFromTop(CardDeck* deck)
{
	Card card;
	
	if (deck->size == 0) {
		printf("Error: Can't remove card from empty deck\n");
		exit(1);
	}
	
	card = deck->cards[deck->size - 1];
	deck->size--;
	
	return card;
}
/*
PSEUDOCODE:
1) Initialise a card
2) Check that the deck has cards in it
	3) If the deck is empty, throw error saying there is no card to remove and exit
4) The initialised card is given the value of the card on top of the given deck
5) The deck has it's size reduced by 1, which effectively deletes the topmost card,
		as it cannot be interacted with unless overwritten using addCartToTop
6) Returns the card removed from the deck
*/

Card removeCardAtIndex(CardDeck* deck, int index)
{
	Card card;
	
	if (index < 0 || index >= deck->size) {
		printf("Error: Outside range\n");
		exit(1);
	}
	
	card = deck->cards[index];
	
	for (int i = index; i < deck->size - 1; i++) {
		deck->cards[i] = deck->cards[i + 1];
	}
	
	deck->size--;
	
	return card;
}
/*
PSEUDOCODE:
1) Initialise a card
2) Check that the index given is within the number of cards in the deck
	3) If not, throw error saying the index is outside the acceptable range of card
4) The initialised card is given the value of the card at the index in the deck's card array
5) The remaining cards after the removed card are shifted down by one to overwrite the removed card and fill the gap
6) Reduces the size of the deck by 1
7) Returns the card removed from the deck
*/

Card peekTopCard(CardDeck* deck)
{
	if (deck->size == 0) {
		fprintf(stderr, "Error: Cannot peek at empty deck\n");
		exit(1);
	}
	
	return deck->cards[deck->size - 1];
}
/*
PSEUDOCODE:
1) Check that the deck isn't empty
	2) If it is, throw an error saying can't check an empty deck and exit
3) Return the value of the top card in the card array
*/

int isDeckEmpty(CardDeck* deck)
{
	return (deck->size == 0);
}
/*
PSEUDOCODE:
1) If the deck size equals 0, return 1 for true
2) Otherwise return 0 for false
*/

int getDeckSize(CardDeck* deck)
{
	return deck->size;
}
/*
PSEUDOCODE:
1) Returns the size of the deck as an integer value
*/

void shuffleDeck(CardDeck* deck)
{
	CardDeck* tempDeck;
	
	if (deck->size <= 1) {
		return;
	}
	
	tempDeck = createCardDeck();
	int n = deck->size;
	
	for (int i = 0; i < n; i++) {
    	int r = rand() % (deck->size - i);
    	Card card = removeCardAtIndex(deck, r);
    	addCardToTop(tempDeck, card);
	}
	
	while (tempDeck->size > 0) {
		Card card;
		card = removeCardFromTop(tempDeck);
		addCardToTop(deck, card);
	}
	
	destroyCardDeck(tempDeck);
}
/*
PSEUDOCODE:
1) Create an empty temporary deck
2) Check the size of the passed deck
	3) If it is of size 1 or less, it can't be shuffled and is returned as is
4) Store the initial size of the passed deck
4) Do a for loop for the initial size of the passed deck
	5) Takes a random card from the passed deck and adds it to the top of the temp deck
6) Do a second loop while there are still cards in the temp deck
	7) Return the now randomised order from the temp deck to the passed deck
8) Destroy the temporary deck
*/

void sortDeck(CardDeck* deck)
{
	int j;
	
	for (int i = 1; i < deck->size; i++) {
		Card key;
		
		key = deck->cards[i];
		j = i - 1;
		
		while (j >= 0 && 
		       (deck->cards[j].suit > key.suit || 
		        (deck->cards[j].suit == key.suit && deck->cards[j].rank > key.rank))) {
			deck->cards[j + 1] = deck->cards[j];
			j--;
		}
		
		deck->cards[j + 1] = key;
	}
}
/*
PSEUDOCODE:
1) The insertion sort starts with the second card as the key card
2) Create a for loop starting at the second card
	3) Set the key card to the current card in the loop, starting at the second card
	4) A second variable is set to the card before the key card
	5) While this second variable is greater than 0 and the key card is less than the indexed card's suit and rank
		6) Shifts the indexed card to the right
	7) Reinserts the key card into the appropriately sorted position
	8) Repeats until all cards are sorted
9) Returns the sorted deck
*/

void printDeck(CardDeck* deck)
{
	for (int i = 0; i < deck->size; i++) {
		printCard(deck->cards[i]);
		if (i < deck->size - 1) {
			printf(", ");
		}
	}
}
/*
PSEUDOCODE:
1) Loops for the size of the passed deck
	2) Prints the cards value using printCard
	3) If the card isn't the last in the deck
		4) Add a comma between card listings
*/

int findMatchingCard(CardDeck* deck, Card card)
{
	for (int i = 0; i < deck->size; i++) {
		if (cardsMatch(deck->cards[i], card)) {
			return i;
		}
	}
	
	return -1;
}
/*
PSEUDOCODE:
1) Loops for the size of the passed deck
	2) Checks the current indexed card against the passed card that's being searched for
	3) If a match is found
		4) Return the index of the first matching card
*/

void transferCards(CardDeck* source, CardDeck* dest)
{
	for (int i = 0; i < source->size; i++) {
		addCardToTop(dest, source->cards[i]);
	}
	
	source->size = 0;
}
/*
PSEUDOCODE:
1) Loops for the size of the source deck
	2) Adds the indexed card of the source deck to the top of the destination deck, 
			starting at the bottom of the source deck
3) Sets the size of the source deck to 0 as it is now empty
*/
