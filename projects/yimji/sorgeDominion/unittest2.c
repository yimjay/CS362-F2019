/*
** Name: Ji Soo Yim
** CS 362 Software Engineering II
** Assignment 3
** Description: This unit test tests the refactored minion card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

#define TESTCARD "MINION"

int main(){
    //set initial variables
    //adapted from cardtest4.c from "Testing for business rules" module
    int i, j , m;
    int handpos = 1, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
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

    //discard minion and gain 2 coins
    choice1 = 1;
    testG.handCount[0] = 10;
    testG.handCount[1] = 10;

    minionCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer);

    printf("Test 1: 2 coins were gained\n");
    if(testG.coins == G.coins + 2){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("Test 2: Action increased by 1\n");
    if(testG.numActions == G.numActions + 1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("Test: Next player does not discard and draw when current player chooses +2 coins\n");
    if(testG.handCount[1] == 10){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));

    //discard hand and gain 4 cards
    choice1 = 0;
    choice2 = 1;
    minionCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer);

    printf("Test 3: 4 cards in current hand\n");
    if(testG.handCount[0] == 4){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("Test 4: 4 cards in next player hand\n");
    if(testG.handCount[1] == 4){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("Test 5: Discard pile has increased by initial hand amount\n");
    if(testG.discardCount[0] == 10){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("Test 6: Coins remain the same\n");
    if(testG.coins == G.coins){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("Test 7: Action increased by 1\n");
    if(testG.numActions == G.numActions + 1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.handCount[1] = 3;
    thisPlayer = 1;
    minionCardEffect(i, j, choice1, choice2, &testG, handpos, thisPlayer);

    printf("Test 8: Next player does not redraw if they have less than 5 cards in hand\n");
    if(testG.handCount[1] == 3){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("\nTESTING COMPLETE FOR %s\n\n", TESTCARD);

    return 0;
}
