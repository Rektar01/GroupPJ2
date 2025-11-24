/**
 * @file main.h
 * @brief header file for main program functions
 * @author Assignment 2 Group
 * @date 20.11.2025
 *
 * This header file containing function declarations for the card game
 * main program logic.
 */

#ifndef MAIN_H
#define MAIN_H

#include "Card.h"
#include "CardDeck.h"

 /**
  * @brief Deals cards to players from the hidden deck
  *
  * Deals the specified number of cards to each player alternately,
  * taking cards from the top of the hidden deck.
  *
  * @param hiddenDeck Pointer to the hidden deck
  * @param player1 Pointer to player 1's deck
  * @param player2 Pointer to player 2's deck
  * @param cardsPerPlayer Number of cards to deal to each player
  */
void dealCards(CardDeck* hiddenDeck, CardDeck* player1, CardDeck* player2, int cardsPerPlayer);

/**
 * @brief Handle a player's turn
 *
 * Checks if the player has a matching card. If yes, play it.
 * If not picks a card from the hidden deck.
 *
 * @param player Pointer to the player's deck
 * @param hiddenDeck Pointer to the hidden deck
 * @param playedDeck Pointer to the played deck
 * @param playerNum Player number (1 or 2)
 */
void playTurn(CardDeck* player, CardDeck* hiddenDeck, CardDeck* playedDeck, int playerNum);

/**
 * @brief Refill hidden deck from played cards
 *
 * When the hidden deck is empty, this function transfers all played cards
 * except the top one to the hidden deck and shuffles it.
 *
 * @param hiddenDeck Pointer to the hidden deck
 * @param playedDeck Pointer to the played deck
 */
void refillHiddenDeck(CardDeck* hiddenDeck, CardDeck* playedDeck);


#endif /* MAIN_H */
