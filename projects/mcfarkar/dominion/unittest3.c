/*  
** Name: Karen McFarland 
** Date: 2/10/2019 
** File: unittest3.c
** Purpose: Write unit tests for the function gainCard
**          int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
** Goal: Write unit tests for four functions (not card implementations, and not cardEffect) 
** in dominion.c “the refactored code you created for assignment-2”. 
** Check these tests in as unittest1.c,unittest2.c, unittest3.c, and unittest4.c. 
** At least two of these functions should be more than 5 lines of code.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

void asserttrue(int testResult) {
  if (testResult == 1)
    printf("TEST SUCCESSFULLY COMPLETED\n");
  else
    printf("TEST FAILED\n");
}

int main () {
  // initialize Gamestate
  int numPlayer = 4;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  int seed = 1234;
  struct gameState G;

  int r, p, t, cardValue, testResult, dc, toPileFlag;
  int testSupply[] = {k[0],sea_hag,k[9]};

  printf ("Testing gainCard.\n");

  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
  p = 2;

  // test if supply pile is empty (0)
  testResult = 0;
  toPileFlag  = 0;
  cardValue = testSupply[2];
  G.supplyCount[cardValue] = 0;              // set the number of cards to 0
  t = gainCard(cardValue, &G, toPileFlag, p);
  if(t == -1) { testResult = 1; }
#if (NOISY_TEST == 1)
                printf("Test if supply pile is empty: ");
                asserttrue(testResult);
#endif

  // test if card is not used in game (-1)
  testResult = 0;
  toPileFlag = 1;
  cardValue = testSupply[1];                 // set to an unused card
  t = gainCard(cardValue, &G, toPileFlag, p);
  if(t == -1) { testResult = 1; }
#if (NOISY_TEST == 1)
                printf("Test if card is not used in game: ");
                asserttrue(testResult);
#endif

  // test if card added correctly: toFlag = 0 : add to discard and supply decremented
  testResult = 0;
  toPileFlag = 0;
  cardValue = testSupply[0];  
  G.discardCount[p] = 0;                     // set player's discard pile size to 0
  dc = G.discardCount[p];
  G.supplyCount[cardValue] = 1;              // set supply pile size to 1
  t = gainCard(cardValue, &G, toPileFlag, p);
  if(t == 0 && G.supplyCount[cardValue] == 0 
      && G.discardCount[p] == 1 
      && G.discard[p][dc] == cardValue) { 
          testResult = 1; 
          }
#if (NOISY_TEST == 1)
                printf("Test if card was correctly discarded and supply decremented: ");
                printf("G.supplyCount %d; expected = %d\n", G.supplyCount[cardValue], 0);
                printf("G.discardCount for player %d: %d; expected = %d\n",p, G.discardCount[p], 1);
                printf("G.discard[p][ G.discardCount[p] ] for player %d: %d; expected = %d\n",p, G.discard[p][dc] , cardValue);
                asserttrue(testResult);
#endif


  // test if card added correctly: toFlag = 1 : add to deck and supply decremented
  testResult = 0;
  toPileFlag = 1;
  cardValue = testSupply[0];  
  G.deckCount[p] = 20;                     // set player's deck pile size to 10
  dc = G.deckCount[p];
  G.supplyCount[cardValue] = 1;              // set supply pile size to 1
  t = gainCard(cardValue, &G, toPileFlag, p);
  if(t == 0 && G.supplyCount[cardValue] == 0 
      && G.deckCount[p] == 21 
      && G.deck[p][dc] == cardValue) { 
          testResult = 1; 
          }
#if (NOISY_TEST == 1)
                printf("Test if card was correctly added to deck and supply decremented: ");
                printf("G.supplyCount %d; expected = %d\n", G.supplyCount[cardValue], 0);
                printf("G.deckCount for player %d: %d; expected = %d\n",p, G.deckCount[p], 21);
                printf("G.deck[p][ G.deckCount[p] ] for player %d: %d; expected = %d\n",p, G.deck[p][dc] , cardValue);
                asserttrue(testResult);
#endif

  // test if card added correctly: toFlag = 2 : add to hand and supply decremented
  testResult = 0;
  toPileFlag = 2;
  cardValue = testSupply[2];  
  G.handCount[p] = 10;                     // set player's hand pile size to 0
  dc = G.handCount[p];  
  G.supplyCount[cardValue] = 1;              // set supply pile size to 1
  t = gainCard(cardValue, &G, toPileFlag, p);
  if(t == 0 && G.supplyCount[cardValue] == 0 
      && G.handCount[p] == 11 
      && G.hand[p][dc] == cardValue) { 
          testResult = 1; 
          }
#if (NOISY_TEST == 1)
                printf("Test if card was correctly added to hand and supply decremented: ");
                printf("G.supplyCount %d; expected = %d\n", G.supplyCount[cardValue], 0);
                printf("G.handCount for player %d: %d; expected = %d\n",p, G.handCount[p], 11);
                printf("G.hand[p][ G.handCount[p] ] for player %d: %d; expected = %d\n",p, G.hand[p][dc] , cardValue);
                asserttrue(testResult);
#endif

  return 0;
}
