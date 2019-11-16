/*
** Name: Ji Soo Yim
** CS 362 Software Engineering II
** Assignment 4
** Description: This random test tests the refactored baron card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TESTCARD "BARON"
#define NUMTESTS 1000000

int inputInt(int min, int max){
    int randomInt = (rand() % (max - min)) + min;
    return randomInt;
}

int main(){
    srand(time(NULL));
    int numPlayers, thisPlayer;
    int choice1 = 0;
    int seed = 1000;
    struct gameState G, testG;
    int k[10] = {baron, minion, ambassador, tribute, mine, adventurer, village, smithy, estate, council_room};

    //printf("-------------------------------TESTING CARD %s-------------------------------\n", TESTCARD);

    int i;
    for(i = 0; i < NUMTESTS; i++){
        //printf("-------------------------------Test number %d\n", i);
        numPlayers = inputInt(1, 2);

        //initialize gameState
        initializeGame(numPlayers, k, seed, &G);
        G.supplyCount[estate] = inputInt(0, MAX_DECK);

        memcpy(&testG, &G, sizeof(struct gameState));

        thisPlayer = inputInt(0, 1);
        choice1 = inputInt(0, 2);
        baronCardEffect(choice1, &testG, thisPlayer);

        testG.hand[thisPlayer][numPlayers] = estate;
        baronCardEffect(choice1, &testG, thisPlayer);
    }

    return 0;
}

