//v1.00 - 8 May 2016
//this testGame tests the initial state of the game
//lacking getWhoseTurn, getExchangeRate, getKPIpoints, isLegalAction

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "game.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}


void newGameTest (Game g);
void getMostTest(Game g);
void testStartingValues(Game g, int disciplines[NUM_REGIONS], int dice[NUM_REGIONS]);


int main (int argc, char * argv[]){
  int disciplines[NUM_REGIONS] = DEFAULT_DISCIPLINES;
  int dice[NUM_REGIONS] = DEFAULT_DICE;
  Game g = newGame (disciplines, dice);

  newGameTest(g);
  getMostTest(g);

  printf("All tests passed, you are Awesome!\n");
  return EXIT_SUCCESS;
}

void newGameTest(Game g){
  printf("Checking creation of new game\n");

  //making sure game is created without crashing and checking condition in Terra Nullis
  int disciplines[NUM_REGIONS];
  int dice [NUM_REGIONS];
  int regionID = 0;

  while(regionID < NUM_REGIONS){
    disciplines[regionID] = STUDENT_BQN;
    dice[regionID] = 9;
    regionID++;
  }
  printf("Successfuly created a new game!\n");

  assert(getTurnNumber(g) == -1);
  assert(getWhoseTurn(g) == 0);

  printf("Terra Nullis condition confirmed\n");
}

void getMostTest(Game g){
  printf("Checking initial state of ARCs and Publications\n");

  //at initial state, no player should have more ARC than others
  assert(getMostARCs(g) == 0);
  assert(getMostPublications(g) == 0);

  printf("Everyone has equal ARCs and Publications, test passed\n");
}

void testStartingValues(Game g, int disciplines[NUM_REGIONS], int dice[NUM_REGIONS]){
  printf("Checking board was initialised properly\n");
  int i = 0;
  while(i < NUM_REGIONS){
    assert(disciplines[i] == getDiscipline(g,i) && dice[i] == getDiceValue(g,i));
    i++;
  }
  printf("All regions are properly done, well done!\n");

  printf("Now moving to check each player's initial values\n");
  int i = UNI_A;
  while(i <= UNI_C){

    assert(getKPIpoints(g,i) == 24);
    assert(getARCs(g,i) == 0);
    assert(getGO8s(g,i)) == 0);
    assert(getCampuses(g,i) == 2);
    assert(getIPs(g,i) == 0);
    assert(getPublications(g,i) == 0);
    assert(getStudents(g,i,STUDENT_THD) == 0);
    assert(getStudents(g,i,STUDENT_BPS) == 3);
    assert(getStudents(g,i,STUDENT_BQN) == 3);
    assert(getStudents(g,i,STUDENT_MTV) == 1);
    assert(getStudents(g,i,STUDENT_MJ) == 1);
    assert(getStudents(g,i,STUDENT_MMONEY) == 1);
  }
  printf("Starting conditions for every uni are on point!\n", );
}
