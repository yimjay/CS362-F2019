/*
** Name: Ji Soo Yim
** CS 362 Software Engineering II
** Assignment 3
** Description: This unit test tests the refactored ambassador card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

#define TESTCARD "AMBASSADOR"

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

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));

    //test 1 choice1 cards were discarded
    choice2 = 1;

    ambassadorCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer);

    printf("Test 2: 1 choice1 cards were discarded\n");
    if(testG.supplyCount[testG.hand[thisPlayer][choice1]] == G.supplyCount[G.hand[thisPlayer][choice1]] + choice2){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));

    //test choice2 boundaries
    choice2 = 3;

    printf("Test 3: If choice2 is more than 2, return error\n");
    if(ambassadorCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer) == -1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //test choice2 boundaries
    choice2 = -1;

    printf("Test 4: If choice2 is less than zero, return error\n");
    if(ambassadorCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer) == -1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //test choice2 boundaries
    choice1 = handpos;

    printf("Test 5: If choice1 is equal to handPos, return error\n");
    if(ambassadorCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer) == -1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("\nTESTING COMPLETE FOR %s\n\n", TESTCARD);

    return 0;
}
