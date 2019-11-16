
/*
** Name: Ji Soo Yim
** CS 362 Software Engineering II
** Assignment 4
** Description: This random test tests the refactored tribute card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TESTCARD "BARON"
#define NUMTESTS 1000

int inputInt(int min, int max){
    int randomInt = (rand() % (max - min)) + min;
    return randomInt;
}

int main(){
    srand(time(NULL));
    int numPlayers, thisPlayer;
    /*int newCards = 0;
    int discarded = 0;
    int extraCoins = 0;
    int shuffledCards = 0;
    int i, j , m;*/
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    //int remove1, remove2;
    int seed = 1000;
    struct gameState G, testG;
    int k[10] = {baron, minion, ambassador, tribute, mine, adventurer, village, smithy, estate, council_room};

    printf("-------------------------------TESTING CARD %s-------------------------------\n", TESTCARD);

    int i;
    for(i = 0; i < NUMTESTS; i++){
        printf("-------------------------------Test number %d\n", i);
        numPlayers = inputInt(1, 2);

        //initialize gameState
        initializeGame(numPlayers, k, seed, &G);

        memcpy(&testG, &G, sizeof(struct gameState));

        thisPlayer = inputInt(0, 1);
        choice1 = inputInt(1, 2);
        baronCardEffect(choice1, &testG, thisPlayer);
    }

    return 0;
}
