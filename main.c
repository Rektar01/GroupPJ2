/**
 * @file main.c
 * @brief Main program for the card game
 * @author Assignment 2 Group
 * @date 21.11.2025
 *
 * This file contains the main game logic for a two-player card game.
 * The game follows these rules:
 * - Each player gets 8 cards initially
 * - Players take turns playing cards that match the top card in suit or rank
 * - If a player cannot play, they pick a card from the hidden deck
 * - First player to empty their hand wins
 * - If hidden deck is empty, played cards are shuffled and reused
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include "CardDeck.h"
#include "main.h"
/**
 * @brief Deal cards to players from the hidden deck
 *
 * Deals the specified number of cards to each player alternately,
 * taking cards from the top of the hidden deck.
 *
 * @param hiddenDeck Pointer to the hidden deck
 * @param player1 Pointer to player 1 deck
 * @param player2 Pointer to player 2 deck
 * @param cardsPerPlayer Number of cards to deal to each player
 */
void dealCards(CardDeck* hiddenDeck, CardDeck* player1, CardDeck* player2, int cardsPerPlayer)
{
	int i;
	
	for (i = 0; i < cardsPerPlayer; i++) {
		Card card;
		
		card = removeCardFromTop(hiddenDeck);
		addCardToTop(player1, card);
		
		card = removeCardFromTop(hiddenDeck);
		addCardToTop(player2, card);
	}
}

/**
 * @brief Handle a player's turn
 *
 * Checks if the player has a matching card. If yes, plays it.
 * If no, picks a card from the hidden deck.
 *
 * @param player Pointer to the player's deck
 * @param hiddenDeck Pointer to the hidden deck
 * @param playedDeck Pointer to the played deck
 * @param playerNum Player number (1 or 2)
 */
void playTurn(CardDeck* player, CardDeck* hiddenDeck, CardDeck* playedDeck, int playerNum)
{
	Card topCard;
	int matchIndex;
	
	topCard = peekTopCard(playedDeck);
	matchIndex = findMatchingCard(player, topCard);
	
	if (matchIndex != -1) {
		Card playedCard;
		
		playedCard = removeCardAtIndex(player, matchIndex);
		addCardToTop(playedDeck, playedCard);
		
		printf("Player %d played card \n", playerNum);
		printCard(playedCard);
		printf("\n");
	} else {
		Card pickedCard;
		
		if (isDeckEmpty(hiddenDeck)) {
			printf("Hidden deck is empty, cannot pick a card\n");
			return;
		}
		
		pickedCard = removeCardFromTop(hiddenDeck);
		addCardToTop(player, pickedCard);
		
		printf("Player %d picks card \n", playerNum);
		printCard(pickedCard);
		printf(" from the hidden deck\n\n");
		
		sortDeck(player);
	}
	
	printf("Player %d cards: \n", playerNum);
	printDeck(player);
	printf("\n\n");
}

/**
 * @brief Refill hidden deck from played cards
 *
 * When the hidden deck is empty, this function transfers all played cards
 * except the top one to the hidden deck and shuffles it.
 *
 * @param hiddenDeck Pointer to the hidden deck
 * @param playedDeck Pointer to the played deck
 */
void refillHiddenDeck(CardDeck* hiddenDeck, CardDeck* playedDeck)
{
	Card topCard;
	
	if (playedDeck->size <= 1) {
		return;
	}
	
	topCard = removeCardFromTop(playedDeck);
	
	transferCards(playedDeck, hiddenDeck);
	
	shuffleDeck(hiddenDeck);
	
	addCardToTop(playedDeck, topCard);
	
	printf("Hidden deck was empty. Played cards have been shuffled and moved to hidden deck.\n\n");
}

/**
 * @brief Main function
 *
 * Entry point for the card game program. Handles user input,
 * initializes the game, and runs the main game loop.
 *
 * @return 0 on successful completion
 */
int main(void)
{
	int numPacks;
	CardDeck* hiddenDeck;
	CardDeck* player1;
	CardDeck* player2;
	CardDeck* playedDeck;
	Card firstCard;
	int gameOver;
	
	srand((unsigned int)time(NULL));
	
	printf("Welcome to the Card Game!\n");
	printf("Enter the number of packs of cards to use: ");
	scanf_s("%d", &numPacks);
	
	if (numPacks < 1) {
		printf("Invalid number of packs. Using 1 pack.\n");
		numPacks = 1;
	}
	
	printf("\nInitializing game with %d pack(s) of cards...\n\n", numPacks);
	
	hiddenDeck = createCardDeckWithPacks(numPacks);
	shuffleDeck(hiddenDeck);
	
	player1 = createCardDeck();
	player2 = createCardDeck();
	playedDeck = createCardDeck();
	
	dealCards(hiddenDeck, player1, player2, 8);
	
	sortDeck(player1);
	sortDeck(player2);
	
	printf("Player 1 cards: \n");
	printDeck(player1);
	printf("\n");
	
	printf("Player 2 cards: \n");
	printDeck(player2);
	printf("\n\n");
	
	firstCard = removeCardFromTop(hiddenDeck);
	addCardToTop(playedDeck, firstCard);
	
	printf("\nFirst card: ");
	printCard(firstCard);
	printf("\n\n");
	
	gameOver = 0;
	
	while (!gameOver) {
		if (isDeckEmpty(hiddenDeck) && playedDeck->size > 1) {
			refillHiddenDeck(hiddenDeck, playedDeck);
		}
		
		playTurn(player1, hiddenDeck, playedDeck, 1);
		
		if (isDeckEmpty(player1)) {
			printf("Player 1 wins!\n");
			gameOver = 1;
			break;
		}
		
		if (isDeckEmpty(hiddenDeck) && playedDeck->size > 1) {
			refillHiddenDeck(hiddenDeck, playedDeck);
		}
		
		playTurn(player2, hiddenDeck, playedDeck, 2);
		
		if (isDeckEmpty(player2)) {
			printf("Player 2 wins!\n");
			gameOver = 1;
			break;
		}
	}
	
	destroyCardDeck(hiddenDeck);
	destroyCardDeck(player1);
	destroyCardDeck(player2);
	destroyCardDeck(playedDeck);
	
	return 0;
}
