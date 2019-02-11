/*  
** Name: Karen McFarland 
** Date: 2/10/2019 
** File: cardtest1.c
** Purpose: Write unit tests for the card smithy
**         int playSmithy(struct gameState *state, int currentPlayer, int handPos)
** Goal: Write unit tests for four Dominion cards implemented in dominion.c. 
** Write these tests so that they work whether a card is implemented inside cardEffect or in its own function. 
** These tests should be checked in as cardtest1.c, cardtest2.c, cardtest3.c, and cardtest4.c. 
** It is mandatory to test smithy and adventurer card.
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

  int r, p, t, cardValue, testResult, dc, toPileFlag, handPos;
  int testSupply[] = {k[0],sea_hag,smithy};

  printf ("Testing smithy.\n");

  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
  p = 3;


  // test if 3 cards added correctly: add to hand and supply decremented
  testResult = 0;
  toPileFlag = 2;
  handPos = 0;
  cardValue = testSupply[2];  
  G.handCount[p] = 10;                     // set player's hand pile size to 10
  dc = G.handCount[p];  
  G.supplyCount[cardValue] = 1;              // set supply pile size to 1
  t = playSmithy(&G, p, handPos);
  if(t == 0 && G.supplyCount[cardValue] == 0 
      && G.handCount[p] == 13 
      && G.hand[p][dc] == cardValue) { 
          testResult = 1; 
          }
#if (NOISY_TEST == 1)
                printf("Test if smithy card was correctly implemented: 3 cards added to hand and supply decremented: ");
                printf("G.supplyCount %d; expected = %d\n", G.supplyCount[cardValue], 0);
                printf("G.handCount for player %d: %d; expected = %d\n",p, G.handCount[p], 13);
                printf("G.hand[p][ G.handCount[p] ] for player %d: %d; expected = %d\n",p, G.hand[p][dc] , cardValue);
                asserttrue(testResult);
#endif

  return 0;
}

