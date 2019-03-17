/*  
** Name: Karen McFarland 
** Date: 2/10/2019 
** File: unittest1.c
** Purpose: Write unit tests for the function numHandCards
**          int numHandCards(struct gameState *state)
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

void asserttrue(int ev, struct gameState *testState) {
  int r;
    
  r = numHandCards(testState);

  if (r == ev)
    printf("numHandCards(): TEST SUCCESSFULLY COMPLETED\n");
  else
    printf("numHandCards(): TEST FAILED\n");
}

int main () {
  // initialize Gamestate
  int numPlayer = 4;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  int seed = 1234;
  struct gameState G;

  int r, p, handCount;
  p = 3;
  handCount = 15;

  printf ("Testing numHandCards.\n");

                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards in player's hand
                G.whoseTurn = p;                            // set the gamestate's whoseturn
                asserttrue(handCount, &G);
#if (NOISY_TEST == 1)
                printf("G.handCount of player %d = %d, expected = %d\n",p, G.handCount[p], handCount);
#endif

  return 0;
}