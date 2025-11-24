/**
 * @file Card.c
 * @brief Implementation of Card data type functions
 * @author Assignment 2 Group
 * @date 19.11.2025
 *
 * This file contains the implementation of functions for the Card data type
 */

#include <stdio.h>
#include "Card.h"


/*
  PSEUDOCODE: getSuitString
 1) Input:suit
 2) Switch for suit:
 3) Check each suit using switch statement
 4) Return a string with the matching suit
 5) If no suit matches, return "Unknown"
 6) Output: string showing the suit
 */

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


/*
 PSEUDOCODE: getSuitRank
 1) Input:rank
 2) Switch for rank:
 3) Check each rank using switch statement
 4) Return a string with the matching rank
 5) If no rank matches, return "Unknown"
 6) Output: string showing the rank
 */

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
	// Arrays for rank and suit symbols
	const char* ranks[] = { "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "Q ", "K ", "A " };
	const char* suits[] = { " club  ", " spade ", " heart ", "diamond" };

	const char* rankStr = ranks[card.rank];
	const char* suitSymbol = suits[card.suit];

	// Print ASCII card
	printf(" _______ \n");
	printf("|%s     |\n", rankStr);
	printf("|       | \n");
	printf("|%s|\n", suitSymbol);
	printf("|       | \n");
	printf("|     %s|\n", rankStr);
	printf(" ------- \n");
}



/*
  PSEUDOCODE: cardsMatch
 1) Input: card1, card2
 2) Check if card1.suit == card2.suit, return true
 3) else if card1.rank == card2.rank, return true
 4) else return false
 */

int cardsMatch(Card card1, Card card2)
{
	return (card1.suit == card2.suit || card1.rank == card2.rank);
}
