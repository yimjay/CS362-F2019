
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
    int k[10] = {baron, minion, ambassador, tribute, mine, adventurer, village, copper, estate, council_room};

    //initialize gameState
    initializeGame(numPlayers, k, seed, &G);

    printf("------------This is the unit test for the %s card\n", TESTCARD);

    //copy current gameState to a test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = estate;

    printf("Test 1: Give error when choosing to trash a non-Treasure card\n");
    if(mineCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer) == -1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = copper;
    choice2 = gold;

    printf("Test 2: Give error when attempting to buy a treasure worth more than 3 more than the trashed one\n");
    if(mineCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer) == -1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = copper;
    choice2 = silver;
    mineCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer);
    printf("Test 3: Trash Copper to gain Silver. Hand counts should remain unchanged\n");
    if(testG.handCount[0] == G.handCount[0]){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("\nTESTING COMPLETE FOR %s\n\n", TESTCARD);

    return 0;
}
