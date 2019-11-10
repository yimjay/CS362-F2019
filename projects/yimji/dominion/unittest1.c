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
    int thisPlayer = 0;
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

    //test 4 coins were gained
    printf("Testing if 4 coins were gained after discarding an Estate\n");
    if(testG.coins == G.coins + 4){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    //reset testG
    memcpy(&testG, &G, sizeof(struct gameState));

    //choose to not discard Estate card to gain an Estate card
    choice1 = 0;
    baronCardEffect(choice1, &testG, thisPlayer);

    //test an Estate card were gained
    printf("Testing if an Estate card was gained after not discarding one\n");
    int cardNotFound = 1;
    int p = 0;
    int count = 0;
    while(cardNotFound){
        if(testG.hand[thisPlayer][p] == "estate"){
            count++;
            if(count < 2){
                p++;
            }else{
                p++;
                cardNotFound = 0;
                printf("TEST PASSED\n");
            }
        }
    }

    printf("\nTESTING COMPLETE FOR %s\n\n", TESTCARD);

    return 0;
}

