/**
 * @file Card.h
 * @brief Header file for Card data type
 * @author Assignment 2 Group
 * @date 2025-11-17
 *
 * This file contains the definition of the Card data type, including
 * enumeration types for Suit and Rank, and the Card structure itself.
 * The Card data type represents a single playing card from a standard
 * 52-card deck.
 */

#ifndef CARD_H
#define CARD_H

/**
 * @brief Enumeration for card suits
 *
 * Represents the four suits in a standard deck of playing cards.
 */
typedef enum {
	CLUB,    /**< Club suit */
	SPADE,   /**< Spade suit */
	HEART,   /**< Heart suit */
	DIAMOND  /**< Diamond suit */
} Suit;

/**
 * @brief Enumeration for card ranks
 *
 * Represents the thirteen ranks in a standard deck of playing cards,
 * from Two (lowest) to Ace (highest).
 */
typedef enum {
	TWO,    /**< Rank Two */
	THREE,  /**< Rank Three */
	FOUR,   /**< Rank Four */
	FIVE,   /**< Rank Five */
	SIX,    /**< Rank Six */
	SEVEN,  /**< Rank Seven */
	EIGHT,  /**< Rank Eight */
	NINE,   /**< Rank Nine */
	TEN,    /**< Rank Ten */
	JACK,   /**< Rank Jack */
	QUEEN,  /**< Rank Queen */
	KING,   /**< Rank King */
	ACE     /**< Rank Ace */
} Rank;

/**
 * @brief Structure representing a playing card
 *
 * A Card consists of a Suit and a Rank, representing one of the 52
 * cards in a standard deck of playing cards.
 */
typedef struct {
	Suit suit;  /**< The suit of the card */
	Rank rank;  /**< The rank of the card */
} Card;

/**
 * @brief Get string representation of a suit
 *
 * @param suit The suit to convert to string
 * @return Pointer to string representation of the suit
 */
const char* getSuitString(Suit suit);

/**
 * @brief Get string representation of a rank
 *
 * @param rank The rank to convert to string
 * @return Pointer to string representation of the rank
 */
const char* getRankString(Rank rank);

/**
 * @brief Print a card to the console
 *
 * Prints the card in the format "Rank-Suit" (e.g., "Five-Spade")
 *
 * @param card The card to print
 */
void printCard(Card card);

/**
 * @brief Check if two cards match in suit or rank
 *
 * Two cards match if they have the same suit OR the same rank.
 *
 * @param card1 First card to compare
 * @param card2 Second card to compare
 * @return 1 if cards match, 0 otherwise
 */
int cardsMatch(Card card1, Card card2);

#endif
