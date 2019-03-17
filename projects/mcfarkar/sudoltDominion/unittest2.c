/*  
** Name: Karen McFarland 
** Date: 2/10/2019 
** File: unittest2.c
** Purpose: Write unit tests for the function isGameOver
**          int isGameOver(struct gameState *state)
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
  r = isGameOver(testState);

  if (r == ev)
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
  struct gameState G, G2;

  int r, p, prov_value;
  int testSupply[] = {duchy,k[5],silver};
  prov_value = province;

  printf ("Testing isGameOver.\n");

                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.supplyCount[prov_value] = 0;              // set the number of Province cards to 0
                asserttrue(1, &G);
#if (NOISY_TEST == 1)
                printf("G.supplyCount of Province = %d; expected = %d\n", G.supplyCount[prov_value], 0);
#endif

                memset(&G2, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G2); // initialize a new game
                for(int i = 0; i < 3; i++){
                    p = testSupply[i];
                    G2.supplyCount[p] = 0;                   // set selected supply pile to 0
                }
                asserttrue(1, &G2);
#if (NOISY_TEST == 1)
                printf("3 supply piles are 0, function returns %d; expected = %d\n", isGameOver(&G2), 1);
#endif

  return 0;
}

