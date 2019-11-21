/*
** Name: Ji Soo Yim
** CS 362 Software Engineering II
** Assignment 3
** Description: This unit test tests the refactored baron card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

#define TESTCARD "BARON"

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
    int thisPlayer = 1;
    struct gameState G, testG;
    int k[10] = {baron, minion, ambassador, tribute, mine, adventurer, village, smithy, estate, council_room};

    //initialize gameState
    initializeGame(numPlayers, k, seed, &G);

    printf("------------This is the unit test for the %s card\n", TESTCARD);

    //copy current gameState to a test gameState
    memcpy(&testG, &G, sizeof(struct gameState));

    //discard Estate card to gain 4 coins
    choice1 = 1;
    baronCardEffect(choice1, &testG, thisPlayer);

    printf("Test 1: 4 coins were gained after discarding an Estate\n");
    if(testG.coins == G.coins + 4){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("Test 2: Hand count was decreased after discarding an Estate\n");
    if(testG.handCount[0] == 9){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("Test 3: Discard pile increased after discarding an Estate\n");
    if(testG.discardCount[0] == 1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //play baron again with no estate card
    choice1 = 0;
    k[8] = sea_hag;
    baronCardEffect(choice1, &testG, thisPlayer);
    printf("Test 4: Gain an estate card if no Estates in hand\n");
    if(testG.handCount[0] == 10){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));

    //gain Estate card
    baronCardEffect(choice1, &testG, thisPlayer);
    int oldSupplyEstate = testG.supplyCount[estate];

    printf("Test 5: Supply pile decreased after gaining an Estate\n");
    if(testG.supplyCount[estate] == oldSupplyEstate - 1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("Test 6: Buys increased when playing card\n");
    if(testG.numBuys == G.numBuys + 1){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    printf("\nTESTING COMPLETE FOR %s\n\n", TESTCARD);

    return 0;
}

