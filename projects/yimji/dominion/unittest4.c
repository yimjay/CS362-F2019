/*
** Name: Ji Soo Yim
** CS 362 Software Engineering II
** Assignment 3
** Description: This unit test tests the refactored tribute card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

#define TESTCARD "TRIBUTE"

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
    int nextPlayer = 1;
    struct gameState G, testG;
    int k[10] = {baron, minion, ambassador, tribute, mine, adventurer, village, smithy, estate, council_room};

    //initialize gameState
    initializeGame(numPlayers, k, seed, &G);

    printf("------------This is the unit test for the %s card\n", TESTCARD);

    //copy current gameState to a test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    int tributeRevealedCards[2] = {copper, copper};
    tributeCardEffect(i, &testG, &tributeRevealedCards, thisPlayer, nextPlayer);

    printf("Test 1: For each differently named Treasure card (cooper, copper), +2 coins\n");
    if(testG.coins == G.coins + 2){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    tributeRevealedCards[0] = copper;
    tributeRevealedCards[1] = silver;
    tributeCardEffect(i, &testG, &tributeRevealedCards, thisPlayer, nextPlayer);

    printf("Test 2: For each differently named Treasure card (copper, silver), +2 coins\n");
    if(testG.coins == G.coins + 4){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    tributeRevealedCards[0] = estate;
    tributeRevealedCards[1] = duchy;
    tributeCardEffect(i, &testG, &tributeRevealedCards, thisPlayer, nextPlayer);

    printf("Test 3: For each differently named Victory card (estate, duchy), +2 cards\n");
    if(testG.handCount == G.handCount + 4){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    tributeRevealedCards[0] = province;
    tributeRevealedCards[1] = gardens;
    tributeCardEffect(i, &testG, &tributeRevealedCards, thisPlayer, nextPlayer);

    printf("Test 4: For each differently named Victory card (province, gardens), +2 cards\n");
    if(testG.handCount == G.handCount + 4){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    tributeRevealedCards[0] = great_hall;
    tributeRevealedCards[1] = great_hall;
    tributeCardEffect(i, &testG, &tributeRevealedCards, thisPlayer, nextPlayer);

    printf("Test 5: For each differently named Victory card (great_hall, great_hall), +2 cards\n");
    if(testG.handCount == G.handCount + 2){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    tributeRevealedCards[0] = baron;
    tributeRevealedCards[1] = minion;
    tributeCardEffect(i, &testG, &tributeRevealedCards, thisPlayer, nextPlayer);

    printf("Test 6: For each differently named Action card (baron, minion), +2 actions\n");
    if(testG.numActions == G.numActions + 4){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    tributeRevealedCards[0] = baron;
    tributeRevealedCards[1] = baron;
    tributeCardEffect(i, &testG, &tributeRevealedCards, thisPlayer, nextPlayer);

    printf("Test 7: For each differently named Action card (baron, baron), +2 actions\n");
    if(testG.numActions == G.numActions + 2){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset test gameState
    memcpy(&testG, &G, sizeof(struct gameState));
    tributeRevealedCards[0] = copper;
    tributeRevealedCards[1] = baron;
    tributeCardEffect(i, &testG, &tributeRevealedCards, thisPlayer, nextPlayer);

    printf("Test 8: For each differently named Treasure and Action card (copper, baron), +2 coins, +2 actions\n");
    if((testG.numActions == G.numActions + 2) && (testG.coins == G.coins + 2)){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }


    printf("\nTESTING COMPLETE FOR %s\n\n", TESTCARD);

    return 0;
}
