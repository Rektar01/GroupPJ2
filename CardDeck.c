/**
 * @file CardDeck.c
 * @brief Implementation of CardDeck data type functions
 * @author Assignment 2 Group
 * @date 2025-11-17
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
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(1);
	}
	
	deck->cards = (Card*)malloc(INITIAL_CAPACITY * sizeof(Card));
	if (deck->cards == NULL) {
		fprintf(stderr, "Error: Memory allocation failed\n");
		free(deck);
		exit(1);
	}
	
	deck->size = 0;
	deck->capacity = INITIAL_CAPACITY;
	
	return deck;
}

CardDeck* createCardDeckWithPacks(int numPacks)
{
	CardDeck* deck;
	int i, s, r;
	
	deck = createCardDeck();
	
	for (i = 0; i < numPacks; i++) {
		for (s = CLUB; s <= DIAMOND; s++) {
			for (r = TWO; r <= ACE; r++) {
				Card card;
				card.suit = (Suit)s;
				card.rank = (Rank)r;
				addCardToTop(deck, card);
			}
		}
	}
	
	return deck;
}

void destroyCardDeck(CardDeck* deck)
{
	if (deck != NULL) {
		if (deck->cards != NULL) {
			free(deck->cards);
		}
		free(deck);
	}
}

void addCardToTop(CardDeck* deck, Card card)
{
	if (deck->size >= deck->capacity) {
		int newCapacity;
		Card* newCards;
		
		newCapacity = deck->capacity * 2;
		newCards = (Card*)realloc(deck->cards, newCapacity * sizeof(Card));
		
		if (newCards == NULL) {
			fprintf(stderr, "Error: Memory reallocation failed\n");
			exit(1);
		}
		
		deck->cards = newCards;
		deck->capacity = newCapacity;
	}
	
	deck->cards[deck->size] = card;
	deck->size++;
}

Card removeCardFromTop(CardDeck* deck)
{
	Card card;
	
	if (deck->size == 0) {
		fprintf(stderr, "Error: Cannot remove card from empty deck\n");
		exit(1);
	}
	
	card = deck->cards[deck->size - 1];
	deck->size--;
	
	return card;
}

Card removeCardAtIndex(CardDeck* deck, int index)
{
	Card card;
	int i;
	
	if (index < 0 || index >= deck->size) {
		fprintf(stderr, "Error: Invalid index\n");
		exit(1);
	}
	
	card = deck->cards[index];
	
	for (i = index; i < deck->size - 1; i++) {
		deck->cards[i] = deck->cards[i + 1];
	}
	
	deck->size--;
	
	return card;
}

Card peekTopCard(CardDeck* deck)
{
	if (deck->size == 0) {
		fprintf(stderr, "Error: Cannot peek at empty deck\n");
		exit(1);
	}
	
	return deck->cards[deck->size - 1];
}

int isDeckEmpty(CardDeck* deck)
{
	return (deck->size == 0);
}

int getDeckSize(CardDeck* deck)
{
	return deck->size;
}

void shuffleDeck(CardDeck* deck)
{
	CardDeck* tempDeck;
	int n;
	
	if (deck->size <= 1) {
		return;
	}
	
	tempDeck = createCardDeck();
	n = deck->size;
	
	while (n > 0) {
		int r;
		Card card;
		
		r = rand() % n;
		card = removeCardAtIndex(deck, r);
		addCardToTop(tempDeck, card);
		n--;
	}
	
	while (tempDeck->size > 0) {
		Card card;
		card = removeCardFromTop(tempDeck);
		addCardToTop(deck, card);
	}
	
	destroyCardDeck(tempDeck);
}

void sortDeck(CardDeck* deck)
{
	int i, j;
	
	for (i = 1; i < deck->size; i++) {
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

void printDeck(CardDeck* deck)
{
	int i;
	
	for (i = 0; i < deck->size; i++) {
		printCard(deck->cards[i]);
		if (i < deck->size - 1) {
			printf(" ");
		}
	}
}

int findMatchingCard(CardDeck* deck, Card card)
{
	int i;
	
	for (i = 0; i < deck->size; i++) {
		if (cardsMatch(deck->cards[i], card)) {
			return i;
		}
	}
	
	return -1;
}

void transferCards(CardDeck* source, CardDeck* dest)
{
	int i;
	
	for (i = 0; i < source->size; i++) {
		addCardToTop(dest, source->cards[i]);
	}
	
	source->size = 0;
}
