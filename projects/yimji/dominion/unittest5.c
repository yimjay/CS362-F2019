
/*
** Name: Ji Soo Yim
** CS 362 Software Engineering II
** Assignment 3
** Description: This unit test tests the refactored mine card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

#define TESTCARD "MINE"

int main(){
    //set initial variables
    //adapted from cardtest4.c from "Testing for business rules" module
    int newCards = 0;
    int discarded = 1;
    int extraCoins = 0;
    int shuffledCards = 0;
    int i, j , m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {baron, minion, ambassador, tribute, mine, adventurer, village, smithy, estate, council_room};

    //initialize gameState
    initializeGame(numPlayers, k, seed, &G);

    printf("------------This is the unit test for the %s card\n", TESTCARD);

    //copy current gameState to a test gameState
    memcpy(&testG, &G, sizeof(struct gameState));

    //test 2 choice1 cards were discarded
    choice1 = 1;
    choice2 = 2;

    ambassadorCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer);

    printf("Test 1: 2 choice1 cards were discarded\n");
    if(testG.supplyCount[testG.hand[thisPlayer][choice1]] == G.supplyCount[G.hand[thisPlayer][choice1]] + choice2){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }


    printf("\nTESTING COMPLETE FOR %s\n\n", TESTCARD);

    return 0;
}
