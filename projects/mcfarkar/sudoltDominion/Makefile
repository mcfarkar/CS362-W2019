CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> randomtestresult.out
	gcov dominion.c >> randomtestresult.out
	cat dominion.c.gcov >> randomtestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

randomtestresults: dominion.h dominion.c rngs.o randomtestcard1.c randomtestcard2.c  randomtestadventurer.c
	
	echo "Result for running dominion tests:" > randomtestcard.out
	echo "randomtestcard1.c:" >> randomtestcard.out
	gcc -o randomtest1 randomtestcard1.c dominion.h dominion.c rngs.o $(CFLAGS)
	./randomtest1 >> randomtestcard.out
	gcov dominion.c -b >> randomtestcard.out
	
#	echo "Result for running dominion tests:" > randomtestcard.out
	echo "randomtestcard2.c:" >> randomtestcard.out
	gcc -g -o randomtest2 randomtestcard2.c dominion.h dominion.c rngs.o $(CFLAGS)
	./randomtest2 >> randomtestcard.out
	gcov dominion.c -b >> randomtestcard.out

#	echo "Result for running dominion tests:" > randomtestcard.out
	echo "randomtestadventurer.c:" >> randomtestcard.out
	gcc -g -o randomtesta randomtestadventurer.c dominion.h dominion.c rngs.o $(CFLAGS)
	./randomtesta >> randomtestcard.out
	gcov dominion.c -b >> randomtestcard.out

unittestresults: dominion.h dominion.c rngs.o unittest1.c  unittest2.c unittest3.c #unittest4.c 
	
	echo "Result for running dominion tests:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 unittest1.c dominion.h dominion.c rngs.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.h dominion.c rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.h dominion.c rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
