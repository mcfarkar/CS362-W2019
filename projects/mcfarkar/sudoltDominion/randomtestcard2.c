/*  
** Name: Karen McFarland 
** Date: 3/2/2019
** File: randomtestcard2.c
** Purpose: Write random tests for the function isGameOver
**          int isGameOver(struct gameState *state)
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
    
  r = isGameOver(testState);

  if (r == ev)
    printf("isGameOver(): TEST SUCCESSFULLY COMPLETED\n");
  else
    printf("isGameOver(): TEST FAILED\n");
}

int main () {

   srand(time(NULL));
  // initialize Gamestate

  // this statement should output random valid input
  // Valid input: Number of players is greater than 2 but 
  //              less than the maximum of allowed players
  int numPlayer = 2 + rand() % (MAX_PLAYERS - 2 + 1);

  int k[10];
  int testSupply[3];
  int cardValue;
  int isFilled = 0;
  int okToAdd = 0;
  int size = 0;

  while (isFilled < 1){
      cardValue = 6 + rand() % (treasure_map - 6 + 1);
      
      if (size == 0){
          k[0] = cardValue;
          size++;
      }
      else {
      for (int i = 0; i < 10; i++) {
          if (cardValue == k[i])
             okToAdd = 1;
             i = 10;
          }
      if (okToAdd == 0){
          k[size + 1] = cardValue;
          size++;
      }
      }

      if (size == 10){
          isFilled = 1;
      }
      }

    testSupply[0] = k[0];
    testSupply[1] = k[1];
    testSupply[2] = k[2];
 

  int seed = 1234;
  struct gameState G, G2;

  int r, p, prov_value;

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