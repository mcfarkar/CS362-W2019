/*  
** Name: Karen McFarland 
** Date: 3/2/2019
** File: randomtestcard1.c
** Purpose: Write random tests for the function numHandCards
**          int numHandCards(struct gameState *state)
** Goal: Write random tests for function
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
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

   srand(time(NULL));
  // initialize Gamestate

  // this statement should output random valid input
  // Valid input: Number of players is greater than 2 but 
  //              less than the maximum of allowed players
  int numPlayer = 2 + rand() % (MAX_PLAYERS - 2 + 1);

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  int seed = 1234;
  struct gameState G;

  int r, p, handCount;

  // this statement should output random valid input
  // Valid input: Random player based on number of players
  p = rand() % numPlayer;

  // this statement should output random valid input
  // Valid input: Handcount is greater than 10 but 
  //              less than the maximum of allowed handcount
  handCount = 10 + rand() %(MAX_HAND  - 10);

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