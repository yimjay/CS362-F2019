#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state,
                int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3,
               struct gameState *state, int handPos, int *bonus);
// Function prototypes for refactored dominion code for 5 cards
// for assignment 2
int mineCardEffect(int i, int j, int choice1, int choice2, struct gameState *state, int handPos, int currentPlayer);
int ambassadorCardEffect(int i, int j, int choice1, int choice2, struct gameState *state, int handPos, int currentPlayer);
int tributeCardEffect(int i, struct gameState *state, int *tributeRevealedCards, int currentPlayer, int nextPlayer);
int minionCardEffect(int i, int j, int choice1, int choice2, struct gameState *state, int handPos, int currentPlayer);
int baronCardEffect(int choice1, struct gameState *state, int currentPlayer);

#endif
