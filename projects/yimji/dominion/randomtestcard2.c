/*
** Name: Ji Soo Yim
** CS 362 Software Engineering II
** Assignment 4
** Description: This random test tests the refactored minion card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TESTCARD "MINION"
#define NUMTESTS 1000000

int inputInt(int min, int max){
    int randomInt = (rand() % (max - min)) + min;
    return randomInt;
}

int main(){
    srand(time(NULL));
    int numPlayers, thisPlayer, nextPlayer;
    int handpos = 0, choice1 = 0, choice2 = 0;
    int seed = 1000;
    struct gameState G, testG;
    int k[10] = {baron, minion, ambassador, tribute, mine, adventurer, village, smithy, estate, council_room};

    //printf("-------------------------------TESTING CARD %s-------------------------------\n", TESTCARD);

    int i, j, m;
    for(i = 0; i < NUMTESTS; i++){
        //printf("-------------------------------Test number %d\n", i);
        numPlayers = 2;

        //initialize gameState
        initializeGame(numPlayers, k, seed, &G);
        thisPlayer = 0;
        nextPlayer = 1;
        G.deckCount[thisPlayer] = inputInt(0, MAX_DECK);
        G.discardCount[thisPlayer] = inputInt(0, MAX_DECK);
        G.handCount[thisPlayer] = inputInt(0, MAX_HAND);
        G.deckCount[nextPlayer] = inputInt(0, MAX_DECK);
        G.discardCount[nextPlayer] = inputInt(0, MAX_DECK);
        G.handCount[nextPlayer] = inputInt(0, MAX_HAND);
        choice1 = inputInt(0, 2);
        choice2 = inputInt(0, 2);
        handpos = inputInt(0, MAX_HAND);

        memcpy(&testG, &G, sizeof(struct gameState));

        minionCardEffect(m, j, choice1, choice2, &testG, handpos, thisPlayer);
    }

    return 0;
}
