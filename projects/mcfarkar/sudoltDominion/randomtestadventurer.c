/*  
** Name: Karen McFarland 
** Date: 3/2/2019 
** File: randomtestadventurer.c
** Purpose: Write random tests for the card adventurer
**         int playAdventurer(struct gameState *state, int currentPlayer, int tempHand[], int *drawntreasure)
int adventurer_card (struct gameState *state, int handPos, int *bonus, int currentPlayer)

This test is isnamed and actually tests the smithy card!!
int smithy_card (struct gameState *state, int currentPlayer, int handPos)
**
**
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
  t = smithy_card(&G, p, handPos);
  //t = playSmithy(&G, p, handPos);
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
