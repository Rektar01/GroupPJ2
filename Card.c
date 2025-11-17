/**
 * @file Card.c
 * @brief Implementation of Card data type functions
 * @author Assignment 2 Group
 * @date 2025-11-17
 *
 * This file contains the implementation of functions for the Card data type.
 */

#include <stdio.h>
#include "Card.h"

const char* getSuitString(Suit suit)
{
	switch (suit) {
	case CLUB:
		return "Club";
	case SPADE:
		return "Spade";
	case HEART:
		return "Heart";
	case DIAMOND:
		return "Diamond";
	default:
		return "Unknown";
	}
}

const char* getRankString(Rank rank)
{
	switch (rank) {
	case TWO:
		return "Two";
	case THREE:
		return "Three";
	case FOUR:
		return "Four";
	case FIVE:
		return "Five";
	case SIX:
		return "Six";
	case SEVEN:
		return "Seven";
	case EIGHT:
		return "Eight";
	case NINE:
		return "Nine";
	case TEN:
		return "Ten";
	case JACK:
		return "Jack";
	case QUEEN:
		return "Queen";
	case KING:
		return "King";
	case ACE:
		return "Ace";
	default:
		return "Unknown";
	}
}

void printCard(Card card)
{
	printf("%s-%s", getRankString(card.rank), getSuitString(card.suit));
}

int cardsMatch(Card card1, Card card2)
{
	return (card1.suit == card2.suit || card1.rank == card2.rank);
}
